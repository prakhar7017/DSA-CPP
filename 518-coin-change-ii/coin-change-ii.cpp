class Solution {
public:
    int n;
    int solveUsingMemo(int idx,int amt,vector<int>& coins,vector<vector<int>>&dp){
        if(idx>=n) return 0;
        if(amt == 0) return 1;
        if(dp[idx][amt]!=-1) return dp[idx][amt];
        int include = 0;
        if(coins[idx]<=amt){
            include = solveUsingMemo(idx,amt-coins[idx],coins,dp);
        }
        int exclude = solveUsingMemo(idx+1,amt,coins,dp);
        return dp[idx][amt]=include+exclude;
    }
    int change(int amount, vector<int>& coins) {
        n = coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
        return solveUsingMemo(0,amount,coins,dp);
    }
};