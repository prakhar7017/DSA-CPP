class Solution {
public:
    bool isSafe(int x, int y, vector<vector<int>>& grid) {
        return x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size();
    }
    int solve(int currX, int currY, vector<vector<int>>& grid, vector<vector<int>>&dp) {
        // base case
        if (currX == grid.size() - 1 && currY == grid[0].size()-1)
            return grid[currX][currY];

        if(dp[currX][currY] != -1) {
            return dp[currX][currY];
        }    

        int goRight = INT_MAX;
        if (isSafe(currX, currY + 1, grid)) {
            goRight = grid[currX][currY] + solve(currX, currY + 1, grid,dp);
        }
        int goDown = INT_MAX;
        if (isSafe(currX + 1, currY, grid)) {
            goDown = grid[currX][currY] + solve(currX + 1, currY, grid,dp);
        }

        return dp[currX][currY]=min(goRight, goDown);
    }
    int minPathSum(vector<vector<int>>& grid) { 
        vector<vector<int>>dp(grid.size(),vector<int>(grid[0].size(),-1));
        return solve(0, 0, grid,dp); 
    }
};