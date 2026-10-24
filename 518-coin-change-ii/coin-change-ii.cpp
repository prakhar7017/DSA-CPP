class Solution {
public:
    int n;
    int solveUsingMemo(int idx, int amt, vector<int>& coins,
                       vector<vector<int>>& dp) {
        if (idx >= n)
            return 0;
        if (amt == 0)
            return 1;
        if (dp[idx][amt] != -1)
            return dp[idx][amt];
        int include = 0;
        if (coins[idx] <= amt) {
            include = solveUsingMemo(idx, amt - coins[idx], coins, dp);
        }
        int exclude = solveUsingMemo(idx + 1, amt, coins, dp);
        return dp[idx][amt] = include + exclude;
    }
    int solveUsingTab(int amount, vector<int>& coins) {
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, 0));
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }
        for (int idx = n - 1; idx >= 0; idx--) {
            for (int amt = 0; amt <= amount; amt++) {
                long long include = 0;
                if (coins[idx] <= amt) {
                    include = dp[idx][amt - coins[idx]];
                }
                long long exclude = dp[idx + 1][amt];
                dp[idx][amt] = include + exclude;
            }
        }
        return dp[0][amount];
    }
    int solveUsingSpace(int amount, vector<int>& coins) {
        vector<int>curr(amount + 1, 0);
        vector<int>next(amount + 1, 0);
        curr[0]=1;
        next[0]=1;
        for (int idx = n - 1; idx >= 0; idx--) {
            for (int amt = 0; amt <= amount; amt++) {
                long long include = 0;
                if (coins[idx] <= amt) {
                    include = curr[amt - coins[idx]];
                }
                long long exclude = next[amt];
                curr[amt] = include + exclude;
            }
            next = curr;
        }
        return next[amount];
    }
    int change(int amount, vector<int>& coins) {
        n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, -1));
        // return solveUsingMemo(0, amount, coins, dp);
        return solveUsingSpace(amount,coins);
    }
};