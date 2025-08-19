class Solution {
public:
    int solveUsingRec(int n,int m,string &s, string &t,vector<vector<int>>&dp){
        // basecase
        if(m==0) return 1;
        if(n==0) return 0;
        if(dp[n][m]!=-1) return dp[n][m];
        int ans=0;
        if(s[n-1]==t[m-1]) ans+=solveUsingRec(n-1,m-1,s,t,dp);
        ans+=solveUsingRec(n-1,m,s,t,dp);
        return dp[n][m]=ans;
    }
    int numDistinct(string s, string t) {
        int n=s.length();
        int m=t.length();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return solveUsingRec(n,m,s,t,dp);
    }
};