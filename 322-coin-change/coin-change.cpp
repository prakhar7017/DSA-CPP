class Solution {
public:
    int n;
    int solveUsingMemo(int idx, int amount, vector<int>& coins,vector<vector<int>>&dp) {
        if (amount == 0)
            return 0;
        if (idx >= coins.size())
            return INT_MAX;
        
        if(dp[idx][amount]!=-1) return dp[idx][amount];

        int include = INT_MAX;
        if (amount >= coins[idx]) {
            int result = solveUsingMemo(idx, amount - coins[idx], coins,dp);
            if (result != INT_MAX) {
                include = 1 + result;
            }
        }
        int exclude = 0 + solveUsingMemo(idx + 1, amount, coins,dp);
        return dp[idx][amount]=min(include, exclude);
    }
    int coinChange(vector<int>& coins, int amount) {
        n = coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
        int ans = solveUsingMemo(0, amount, coins,dp);

        return ans == INT_MAX ? -1 : ans;
    }
};