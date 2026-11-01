class Solution {
public:
    int n;
    int m;
    bool isSafe(int x,int y){
        if(x>=0 && x<n && y>=0 && y<m) return true;
        return false;
    }
    vector<vector<int>>directions={{0,1},{1,0},{0,-1},{-1,0}};
    int DFS(int i,int j,vector<vector<int>>& matrix,vector<vector<int>>&dp){
        if(dp[i][j]!=-1) return dp[i][j];
        int pathLength = 1;
        for(vector<int>dir:directions){
            int newX = i + dir[0];
            int newY = j + dir[1];
            if(isSafe(newX,newY) && matrix[newX][newY]>matrix[i][j]){
                pathLength=max(pathLength,1+DFS(newX,newY,matrix,dp));
            }
        }
        return dp[i][j]=pathLength;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        n = matrix.size();
        m = matrix[0].size();
        int ans=INT_MIN;
        vector<vector<int>>dp(n,vector<int>(m,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans = max(ans,DFS(i,j,matrix,dp));
            }
        }
        return ans;
    }
};