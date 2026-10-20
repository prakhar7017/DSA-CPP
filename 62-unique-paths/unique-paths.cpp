class Solution {
public:
    int count;
    vector<vector<int>>directions = {{1,0},{0,1}};
    bool isSafe(int i,int j,int m,int n){
        if(i>=0 && i<m && j>=0 && j<n) return true;
        return false;
    }
    int countPaths(int i,int j,int m,int n,vector<vector<int>>&dp){
        if(i==m-1 && j==n-1) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        int count = 0;
        for(vector<int>&dir:directions){
            int _i = i + dir[0];
            int _j = j + dir[1];
            if(isSafe(_i,_j,m,n)){
                count += countPaths(_i,_j,m,n,dp);
            }
        }
        return dp[i][j]=count;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return countPaths(0,0,m,n,dp);
    }
};