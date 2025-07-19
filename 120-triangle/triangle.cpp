class Solution {
public:
    int rows;
    int cols;
    vector<vector<int>>directions{{1,0},{1,1}};
    bool isSafe(int x, int y,vector<vector<int>>& t){
        return x < rows && y < t[x].size();
    }
    int solve(int x,int y,vector<vector<int>>& t,vector<vector<int>>&dp){
        // base case
        if(x==rows-1) return t[x][y];
        if(dp[x][y]!=-1) return dp[x][y];
        int minPath=INT_MAX;
        for(vector<int>&dir:directions){
            int newX=x+dir[0];
            int newY=y+dir[1];
            if(isSafe(newX,newY,t)){
                minPath=min(minPath,solve(newX,newY,t,dp));
            }
        }
        return dp[x][y]=t[x][y]+minPath;
    }
    int solveUsingTab(vector<vector<int>>& t){
        vector<vector<int>>dp(rows,vector<int>(rows,0));
        for(int col=0;col<t[rows-1].size();col++) dp[rows-1][col]=t[rows-1][col];

        for(int row=rows-2;row>=0;row--){
            for(int col=0;col<t[row].size();col++){
                dp[row][col]=t[row][col]+min(dp[row+1][col],dp[row+1][col+1]);
            }
        }
        return dp[0][0];
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        rows=triangle.size();
        cols=triangle[0].size();
        // vector<vector<int>>dp(rows,vector<int>(rows,-1));
        // return solve(0,0,triangle,dp);
        return solveUsingTab(triangle);
    }
};