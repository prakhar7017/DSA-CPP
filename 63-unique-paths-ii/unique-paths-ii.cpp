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
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid[0][0] == 1)
            return 0;
        vector<vector<int>> dp(obstacleGrid.size(),
                               vector<int>(obstacleGrid[0].size(), -1));

        return solve(0, 0, obstacleGrid, dp);
    }
};