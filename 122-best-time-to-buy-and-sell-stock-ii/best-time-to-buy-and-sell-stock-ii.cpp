class Solution {
public:
    int n;
    int solveUsingMemo(int idx, int canBuy, vector<int>& prices,
                       vector<vector<int>>& dp) {
        if (idx >= n)
            return 0;
        if (dp[idx][canBuy] != -1)
            return dp[idx][canBuy];
        int profit = 0;
        if (canBuy) {
            int buykaro = -prices[idx] + solveUsingMemo(idx + 1, 0, prices, dp);
            int ignore = 0 + solveUsingMemo(idx + 1, 1, prices, dp);
            profit = max(buykaro, ignore);
        } else {
            int sellkaro =
                +prices[idx] + solveUsingMemo(idx + 1, 1, prices, dp);
            int ignore = 0 + solveUsingMemo(idx + 1, 0, prices, dp);
            profit = max(sellkaro, ignore);
        }
        return dp[idx][canBuy] = profit;
    }
    int solveUsingBottomUp(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        for (int idx = n - 1; idx >= 0; idx--) {
            for (int canBuy = 0; canBuy <=1; canBuy++) {
                int profit = 0;
                if (canBuy) {
                    int buykaro = -prices[idx] + dp[idx + 1][0];
                    int ignore = 0 + dp[idx + 1][1];
                    profit = max(buykaro, ignore);
                } else {
                    int sellkaro = +prices[idx] + dp[idx + 1][1];
                    int ignore = 0 + dp[idx + 1][0];
                    profit = max(sellkaro, ignore);
                }
                dp[idx][canBuy]=profit;
            }
        }
        return dp[0][1];
    }
    int solveUsingSpaceOptmised(vector<int>& prices) {
        int n = prices.size();
        vector<int>curr(2,0);
        vector<int>next(2,0);
        for (int idx = n - 1; idx >= 0; idx--) {
            for (int canBuy = 0; canBuy <=1; canBuy++) {
                int profit = 0;
                if (canBuy) {
                    int buykaro = -prices[idx] + next[0];
                    int ignore = 0 + next[1];
                    profit = max(buykaro, ignore);
                } else {
                    int sellkaro = +prices[idx] + next[1];
                    int ignore = 0 + next[0];
                    profit = max(sellkaro, ignore);
                }
                curr[canBuy]=profit;
            }
            next = curr;
        }
        return next[1];
    }
    int maxProfit(vector<int>& prices) {
        n = prices.size();
        int canBuy = 1; // 1:allowed and 0:not allowed
        vector<vector<int>> dp(n + 1, vector<int>(2, -1));
        // return solveUsingMemo(0, 1, prices, dp);
        return solveUsingSpaceOptmised(prices);
    }
};