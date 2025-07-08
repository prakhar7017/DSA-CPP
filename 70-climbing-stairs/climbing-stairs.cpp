class Solution {
public:
    int solveUsingRec(int n){
        if(n==0) return 1;
        if(n<0) return 0;
        return solveUsingRec(n-1)+solveUsingRec(n-2);
    }
    int solveUsingDP(int n,vector<int>&dp){
        if(n==0) return 1;
        if(n<0) return 0;
        if(dp[n]!=0) return dp[n];
        return dp[n]=solveUsingDP(n-1,dp)+solveUsingDP(n-2,dp);
    }
    int solveUsingBottomUp(int n){
        vector<int>dp(n+1,-1);

        dp[0]=1;
        dp[1]=1;
        for(int i=2;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
    int solveUsingSpaceOptimised(int n){
        int prev1=1;
        int prev2=1;
        for(int i=2;i<=n;i++){
            int curr=prev1+prev2;
            prev2=prev1;
            prev1=curr;
        }
        return prev1;
    }
    int climbStairs(int n) {
        // return solveUsingRec(n);
        vector<int>dp(n+1,0);
        // return solveUsingDP(n,dp);
        // return solveUsingBottomUp(n);
        return solveUsingSpaceOptimised(n);
    }
};