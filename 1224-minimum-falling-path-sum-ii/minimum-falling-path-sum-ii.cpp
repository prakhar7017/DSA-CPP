class Solution {
public:
    int rows;
    int cols;
    int solveUsingMemo(int row,int col,vector<vector<int>>& grid,vector<vector<int>>& dp){
        // base case
        if(row==rows-1){ // on last row
            return grid[row][col];
        }
        if(dp[row][col]!=-1){
            return dp[row][col];
        }
        int ans=INT_MAX;
        for(int nextCol=0;nextCol<cols;nextCol++){
            if(nextCol!=col){
                ans=min(ans,solveUsingMemo(row+1,nextCol,grid,dp));
            }
        }

        return dp[row][col]=grid[row][col]+ans; // current[row][col] + neche ki rows ka min ans
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        rows=grid.size();
        cols=grid[0].size();
        int result=INT_MAX;
        vector<vector<int>>dp(rows+1,vector<int>(cols+1,-1));
        for(int col=0;col<cols;col++){
            result=min(result,solveUsingMemo(0,col,grid,dp));
        }
        return result;
    }
};