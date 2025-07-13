class Solution {
public:
    vector<vector<int>> directions{{0, 1}, {1, 0}};
    bool isSafe(int x, int y, vector<vector<int>>& grid) {
        return x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size() &&
               grid[x][y] != 1;
    }
    int solve(int x, int y, vector<vector<int>>& grid,
              vector<vector<int>>& dp) {
        if (x == grid.size() - 1 && y == grid[0].size() - 1)
            return 1;

        if (dp[x][y] != -1)
            return dp[x][y];
        int totalPaths = 0;
        for (vector<int>& dir : directions) {
            int newX = x + dir[0];
            int newY = y + dir[1];
            if (isSafe(newX, newY, grid)) {
                totalPaths += solve(newX, newY, grid, dp);
            }
        }
        return dp[x][y] = totalPaths;
    }
    int solveUsingTab(int rows, int cols, vector<vector<int>>& grid) {
        vector<vector<int>> dp(rows, vector<int>(cols, 0));
        dp[0][0] = (grid[0][0] == 0) ? 1 : 0;
        for (int col = 1; col < cols; col++) {
            if (col >= 1 && grid[0][col - 1] == 1) {
                dp[0][col] = 0;
                grid[0][col] = 1;
            } else if (grid[0][col] == 1) {
                dp[0][col] = 0;
            } else
                dp[0][col] = 1;
        }

        for (int row = 1; row < rows; row++) {
            if (row >= 1 && grid[row - 1][0] == 1) {
                dp[row][0] = 0;
                grid[row][0] = 1;
            } else if (grid[row][0] == 1)
                dp[row][0] = 0;
            else
                dp[row][0] = 1;
        }

        for (int row = 1; row < rows; row++) {
            for (int col = 1; col < cols; col++) {
                if (grid[row][col] == 1)
                    dp[row][col] = 0;
                else
                    dp[row][col] = dp[row - 1][col] + dp[row][col - 1];
            }
        }
        return dp[rows - 1][cols - 1];
    }
    int solveUsingSpace(int rows, int cols, vector<vector<int>>& grid) {
        vector<int> prev(cols, 0);
        prev[0] = (grid[0][0] == 0) ? 1 : 0;
        for (int col = 1; col < cols; col++) {
            if (grid[0][col] == 0)
                prev[col] = prev[col - 1];
            else
                prev[col] = 0;
        }
        for (int row = 1; row < rows; row++) {
            vector<int> curr(cols, 0);
            // First column of current row
            if (grid[row][0] == 0)
                curr[0] = prev[0];
            else
                curr[0] = 0;

            // Rest of the row
            for (int col = 1; col < cols; col++) {
                if (grid[row][col] == 0)
                    curr[col] = prev[col] + curr[col - 1];
                else
                    curr[col] = 0;
            }

            prev = curr;
        }
        return prev[cols - 1];
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int rows = obstacleGrid.size();
        int cols = obstacleGrid[0].size();
        // if (obstacleGrid[0][0] == 1)
        //     return 0;
        // vector<vector<int>> dp(obstacleGrid.size(),
        //                        vector<int>(obstacleGrid[0].size(), -1));

        return solveUsingSpace(rows, cols, obstacleGrid);
    }
};