class Solution {
public:
    int solveUsingRec(int index, int buy, int fee, vector<int>& prices,
                      vector<vector<int>>& dp) {
        if (index >= prices.size())
            return 0;

        if (dp[index][buy] != -1)
            return dp[index][buy];

        int profit = 0;
        if (buy) {
            profit = max(-prices[index] +
                             solveUsingRec(index + 1, 0, fee, prices, dp),
                         0 + solveUsingRec(index + 1, 1, fee, prices, dp));
        } else {
            profit = max(-fee + prices[index] +
                             solveUsingRec(index + 1, 1, fee, prices, dp),
                         0 + solveUsingRec(index + 1, 0, fee, prices, dp));
        }
        return dp[index][buy] = profit;
    }

    int solveUsingTab(int fee, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2, 0));
        int profit = 0;
        for (int index = n - 1; index >= 0; index--) {
            for (int buy = 0; buy <= 1; buy++) {
                if (buy) {
                    profit = max(-prices[index] + dp[index + 1][0],
                                 0 + dp[index + 1][1]);
                } else {
                    profit = max(-fee + prices[index] + dp[index + 1][1],
                                 0 + dp[index + 1][0]);
                }
                dp[index][buy]=profit;
            }
        }
        return dp[0][1];
    }

    int solveUsingSpaceOptmizes(int fee, vector<int>& prices) {
        int n = prices.size();
        vector<int>next(2, 0);
        vector<int>curr(2, 0);
        int profit = 0;
        for (int index = n - 1; index >= 0; index--) {
            for (int buy = 0; buy <= 1; buy++) {
                if (buy) {
                    profit = max(-prices[index] + next[0],
                                 0 + next[1]);
                } else {
                    profit = max(-fee + prices[index] + next[1],
                                 0 + next[0]);
                }
                curr[buy]=profit;
            }
            next=curr;
        }
        return next[1];
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return solveUsingSpaceOptmizes(fee,prices);
    }
};