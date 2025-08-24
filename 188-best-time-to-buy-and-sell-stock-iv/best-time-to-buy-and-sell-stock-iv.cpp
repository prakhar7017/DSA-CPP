class Solution {
public:
    int solveUsingRec(int index, int buy, int k, vector<int>& prices,
                      vector<vector<vector<int>>>& dp) {
        // basecase
        if (index >= prices.size() || k == 0)
            return 0;
        if (dp[index][buy][k] != -1)
            return dp[index][buy][k];
        int profit = 0;
        if (buy) {
            profit =
                max(-prices[index] + solveUsingRec(index + 1, 0, k, prices, dp),
                    0 + solveUsingRec(index + 1, 1, k, prices, dp));
        } else {
            profit = max(prices[index] +
                             solveUsingRec(index + 1, 1, k - 1, prices, dp),
                         0 + solveUsingRec(index + 1, 0, k, prices, dp));
        }
        return dp[index][buy][k] = profit;
    }

    int solveUsingTab(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(
            n+1, vector<vector<int>>(2, vector<int>(k + 1, 0)));
        int profit;
        for (int index = n - 1; index >= 0; index--) {
            for (int buy = 0; buy <= 1; buy++) {
                for (int cap = 1; cap <= k; cap++) {
                    if (buy) {
                        profit = max(-prices[index] + dp[index + 1][0][cap],
                                     0 + dp[index + 1][1][cap]);
                    } else {
                        profit = max(prices[index] + dp[index + 1][1][cap - 1],
                                     0 + dp[index + 1][0][cap]);
                    }
                    dp[index][buy][cap]=profit;
                }
            }
        }
        return dp[0][1][k];
    }

    int solveUsingSpace(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>next(2, vector<int>(k + 1, 0));
        vector<vector<int>>curr(2, vector<int>(k + 1, 0));
        int profit;
        for (int index = n - 1; index >= 0; index--) {
            for (int buy = 0; buy <= 1; buy++) {
                for (int cap = 1; cap <= k; cap++) {
                    if (buy) {
                        profit = max(-prices[index] + next[0][cap],
                                     0 + next[1][cap]);
                    } else {
                        profit = max(prices[index] + next[1][cap - 1],
                                     0 + next[0][cap]);
                    }
                    curr[buy][cap]=profit;
                }
            }
            next=curr;
        }
        return next[1][k];
    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(2, vector<int>(k + 1, -1)));

        // return solveUsingRec(0, 1, k, prices, dp);
        return solveUsingSpace(k, prices);
    }
};