class Solution {
public:
    int rows;
    int cols;
    vector<vector<int>> directions{{1, -1}, {1, 0}, {1, 1}};
    bool isSafe(int x, int y) {
        return x >= 0 && x < rows && y >= 0 && y < cols;
    }
    int solve(int x, int y, vector<vector<int>>& m, vector<vector<int>>& dp) {
        // basecase
        if (x == rows - 1)
            return m[x][y];
        if (dp[x][y] != -1)
            return dp[x][y];
        int minAns = INT_MAX;
        for (vector<int>& dir : directions) {
            int newX = x + dir[0];
            int newY = y + dir[1];
            if (isSafe(newX, newY)) {
                minAns = min(minAns, solve(newX, newY, m, dp));
            }
        }
        return dp[x][y] = m[x][y] + minAns;
    }
    int solveUsingTab(vector<vector<int>>& m) {
        vector<vector<int>> dp(rows, vector<int>(cols, 0));

        for (int col = 0; col < cols; col++)
            dp[rows - 1][col] = m[rows - 1][col];

        for (int row = rows - 2; row >= 0; row--) {
            for (int col = 0; col < cols; col++) {
                if (col == 0)
                    dp[row][col] = m[row][col] +
                                   min(dp[row + 1][col], dp[row + 1][col + 1]);
                else if (col == cols - 1)
                    dp[row][col] = m[row][col] +
                                   min(dp[row + 1][col - 1], dp[row + 1][col]);
                else
                    dp[row][col] = m[row][col] + min(dp[row + 1][col - 1],
                                                     min(dp[row + 1][col],
                                                         dp[row + 1][col + 1]));
            }
        }

        int ans=INT_MAX;
        for(int col=0;col<cols;col++){
            ans=min(ans,dp[0][col]);
        }
        return ans;
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        rows = matrix.size();
        cols = matrix[0].size();
        // int minAns = INT_MAX;
        // vector<vector<int>> dp(rows + 1, vector<int>(cols + 1, -1));
        // for (int col = 0; col < cols; col++) {
        //     minAns = min(minAns, solve(0, col, matrix, dp));
        // }
        // return minAns;
        return solveUsingTab(matrix);
    }
};