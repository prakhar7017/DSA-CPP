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
    int solveUsingTab(vector<vector<int>>& grid){
        int rows=grid.size();
        int cols=grid[0].size();
        vector<vector<int>>dp(rows+1,vector<int>(cols+1,0));
        dp[0][0]=grid[0][0];
        for(int row=1;row<rows;row++) dp[row][0]=dp[row-1][0]+grid[row][0];
        for(int col=1;col<cols;col++) dp[0][col]=dp[0][col-1]+grid[0][col];

        for(int row=1;row<rows;row++){
            for(int col=1;col<cols;col++){
                dp[row][col]=grid[row][col]+min(dp[row-1][col],dp[row][col-1]);
            }
        }
        return dp[rows-1][cols-1];
    }
    int solveUsingSpaceOp(vector<vector<int>>& grid){
        int rows=grid.size();
        int cols=grid[0].size();
        vector<int>prev(cols+1,0);
        prev[0]=grid[0][0];
        for(int col=1;col<cols;col++) prev[col]=prev[col-1]+grid[0][col];
        for(int row=1;row<rows;row++){
            vector<int>curr(cols+1,0);
            for(int col=0;col<cols;col++){
                if(col==0) curr[0]=grid[row][col]+prev[col];
                else curr[col]=grid[row][col]+min(prev[col],curr[col-1]);
            }
            prev=curr;
        }
        return prev[cols-1];
    }
    int minPathSum(vector<vector<int>>& grid) { 
        // vector<vector<int>>dp(grid.size(),vector<int>(grid[0].size(),-1));
        // return solve(0, 0, grid,dp); 
        // return solveUsingTab(grid);
        return solveUsingSpaceOp(grid);
    }
};