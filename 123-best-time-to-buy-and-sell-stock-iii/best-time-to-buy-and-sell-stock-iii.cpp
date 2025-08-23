class Solution {
public:
    int solveUsingRec(int index, int buy, int cap, vector<int>& prices,
                      vector<vector<vector<int>>>& dp) {
        if (index >= prices.size() || cap == 0)
            return 0;
        if (dp[index][buy][cap] != -1)
            return dp[index][buy][cap];
        int profit = 0;
        if (buy) {
            profit = max(-prices[index] +
                             solveUsingRec(index + 1, 0, cap, prices, dp),
                         0 + solveUsingRec(index + 1, 1, cap, prices, dp));

        } else {
            profit = max(prices[index] +
                             solveUsingRec(index + 1, 1, cap - 1, prices, dp),
                         0 + solveUsingRec(index + 1, 0, cap, prices, dp));
        }
        return dp[index][buy][cap] = profit;
    }

    int solveUsingTab(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(
            n + 1, vector<vector<int>>(2, vector<int>(3, 0)));
        int profit;
        for (int index = n - 1; index >= 0; index--) {
            for (int buy = 0; buy <= 1; buy++) {
                for (int cap = 1; cap <= 2; cap++) {
                    if (buy) {
                        profit = max(-prices[index] + dp[index + 1][0][cap],
                                     0 + dp[index + 1][1][cap]);

                    } else {
                        profit = max(prices[index] + dp[index + 1][1][cap - 1],
                                     0 + dp[index + 1][0][cap]);
                    }
                    dp[index][buy][cap] = profit;
                }
            }
        }
        return dp[0][1][2];
    }

    int solveUsingSpace(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> next(2, vector<int>(3, 0));
        vector<vector<int>> curr(2, vector<int>(3, 0));
        int profit;
        for (int index = n - 1; index >= 0; index--) {
            for (int buy = 0; buy <= 1; buy++) {
                for (int cap = 1; cap <= 2; cap++) {
                    if (buy) {
                        profit = max(-prices[index] + next[0][cap],
                                     0 + next[1][cap]);

                    } else {
                        profit = max(prices[index] + next[1][cap - 1],
                                     0 + next[0][cap]);
                    }
                    curr[buy][cap] = profit;
                }
            }
            next=curr;
        }
        return next[1][2];
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int cap = 2;
        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(2, vector<int>(3, -1)));
        // return solveUsingRec(0, 1, cap, prices, dp);
        return solveUsingSpace(prices);
    }
};