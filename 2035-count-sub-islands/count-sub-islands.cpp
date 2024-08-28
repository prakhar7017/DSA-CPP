class Solution {
public:
    // Helper function to perform DFS and check if a sub-island exists
    int solve(int i, int j, int n, int m, vector<vector<int>>& dp, vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        dp[i][j] = 1;
        int ans = 1;

        // Move down
        if (i < n - 1 && grid2[i + 1][j] == 1 && dp[i + 1][j] == 0) {
            ans &= solve(i + 1, j, n, m, dp, grid1, grid2);
        }
        // Move up
        if (i > 0 && grid2[i - 1][j] == 1 && dp[i - 1][j] == 0) {
            ans &= solve(i - 1, j, n, m, dp, grid1, grid2);
        }
        // Move right
        if (j < m - 1 && grid2[i][j + 1] == 1 && dp[i][j + 1] == 0) {
            ans &= solve(i, j + 1, n, m, dp, grid1, grid2);
        }
        // Move left
        if (j > 0 && grid2[i][j - 1] == 1 && dp[i][j - 1] == 0) {
            ans &= solve(i, j - 1, n, m, dp, grid1, grid2);
        }

        // Check if the current cell is part of an island in grid1
        ans &= grid1[i][j];

        return ans;
    }

    // Function to count the number of sub-islands
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n = grid1.size();
        int m = grid1[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        int ans = 0;

        // Iterate through each cell in grid2
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // If the cell is part of an unvisited island in grid2
                if (dp[i][j] == 0 && grid2[i][j] == 1) {
                    // Check if it is a sub-island
                    ans += solve(i, j, n, m, dp, grid1, grid2);
                }
            }
        }

        return ans;
    }
};