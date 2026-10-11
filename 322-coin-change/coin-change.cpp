class Solution {
public:
    int solve(int index,int amount,int n,vector<int>& coins,vector<vector<int>>&dp){
        if(amount == 0) return 0;
        if(amount<0 || index>=n) return INT_MAX;
        if(dp[index][amount]!=-1) return dp[index][amount];
        int include = solve(index,amount-coins[index],n,coins,dp);
        if(include !=INT_MAX) {
            include+=1;
        }
        int exclude = solve(index+1,amount,n,coins,dp);
        return dp[index][amount]=min(include,exclude);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
        int ans = solve(0,amount,n,coins,dp);
        return ans == INT_MAX ? -1 : ans;
    }
};