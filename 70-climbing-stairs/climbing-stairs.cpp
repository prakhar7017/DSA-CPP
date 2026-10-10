class Solution {
public:
    int solveUsingDP(int n, vector<int>&dp){
        if(n<0) return 0;
        if(n==0) return 1;
        if(dp[n]!=0) return dp[n]; 
        return dp[n]=solveUsingDP(n-1,dp) + solveUsingDP(n-2,dp);
    }
    int climbStairs(int n) {
        vector<int>dp(n+1,0);
        return solveUsingDP(n,dp);
    }
};