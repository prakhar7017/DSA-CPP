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

    int solve1(int index, vector<int>& coins, int amount,
               vector<vector<int>>& dp) {
        if (index == 0) {
            if (amount % coins[0] == 0)
                return amount / coins[0];
            return INT_MAX;
        }

        if (dp[index][amount] != -1)
            return dp[index][amount];

        int exclude = solve1(index - 1, coins, amount, dp);
        int include = INT_MAX;
        if (coins[index] <= amount) {
            int subRes = solve1(index, coins, amount - coins[index], dp);
            if (subRes != INT_MAX)
                include = 1 + subRes;
        }

        return dp[index][amount] = min(include, exclude);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        // vector<int> dp(amount + 1, -1);
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        int ans = solve1(n-1, coins, amount, dp);
        if (ans >= 1e9)
            return -1;
        else
            return ans;
    }
};