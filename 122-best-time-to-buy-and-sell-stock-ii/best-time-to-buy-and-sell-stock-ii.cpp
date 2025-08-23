class Solution {
public:
    int solveUsingRec(int index, int buy, vector<int>& prices,
                      vector<vector<int>>& dp) {
        if (index >= prices.size())
            return 0;
        if (dp[index][buy] != -1)
            return dp[index][buy];
        int profit = 0;
        if (buy) {
            profit =
                max(-prices[index] + solveUsingRec(index + 1, 0, prices, dp),
                    0 + solveUsingRec(index + 1, 1, prices, dp));

        } else {
            profit =
                max(prices[index] + solveUsingRec(index + 1, 1, prices, dp),
                    0 + solveUsingRec(index + 1, 0, prices, dp));
        }
        return dp[index][buy] = profit;
    }

    int solveUsingRec(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        // basecase
        dp[n][0] = dp[n][1] = 0;
        int profit;
        for (int index = n - 1; index >= 0; index--) {
            for (int buy = 1; buy >= 0; buy--) {
                if (buy) {
                    profit = max(-prices[index] + dp[index + 1][0],
                                 0 + dp[index + 1][1]);

                } else {
                    profit = max(prices[index] + dp[index + 1][1],
                                 0 + dp[index + 1][0]);
                }
                dp[index][buy] = profit;
            }
        }
        return dp[0][1];
    }

    int solveUsingSpaceOptimized(vector<int>& prices) {
        int n = prices.size();
        vector<int> next(2, 0);
        // basecase
        next[0] = next[1] = 0;
        int profit;
        for (int index = n - 1; index >= 0; index--) {
            vector<int> curr(2, 0);
            for (int buy = 1; buy >= 0; buy--) {
                if (buy) {
                    profit = max(-prices[index] + next[0], 0 + next[1]);

                } else {
                    profit = max(prices[index] + next[1], 0 + next[0]);
                }
                curr[buy] = profit;
                next=curr;
            }
        }
        return next[1];
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        // return solveUsingRec(0, 1, prices, dp);
        return solveUsingSpaceOptimized(prices);
    }
};