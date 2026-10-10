class Solution {
public:
    int solveUsingDP(int n, vector<int>&dp){
        if(n<0) return 0;
        if(n==0) return 1;
        if(dp[n]!=0) return dp[n]; 
        return dp[n]=solveUsingDP(n-1,dp) + solveUsingDP(n-2,dp);
    }
    int bottomUp(int n ){
        vector<int>dp(n+1,-1);
        dp[0]=1;
        dp[1]=1;
        for(int i=2;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
    int climbStairs(int n) {
        vector<int>dp(n+1,0);
        return bottomUp(n);
    }
};