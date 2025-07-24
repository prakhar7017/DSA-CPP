class Solution {
public:
    int solve(int n, vector<int>& coins, int amount, vector<int>& dp) {
        if (amount == 0)
            return 0;
        if (dp[amount] != -1)
            return dp[amount];
        int minCoins = INT_MAX;
        for (int coin = 0; coin < n; coin++) {
            if (coins[coin] <= amount) {
                int ans = solve(n, coins, amount - coins[coin], dp);
                if (ans != INT_MAX) {
                    minCoins = min(minCoins, 1 + ans);
                }
            }
        }
        return dp[amount] = minCoins;
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> dp(amount+1,-1);
        int ans = solve(n, coins, amount, dp);
        if (ans == INT_MAX)
            return -1;
        else
            return ans;
    }
};