class Solution {
public:
    int n;
    int solveUsingMemo(int idx, int canBuy, int limit, vector<int>& prices,
                       vector<vector<vector<int>>>& dp) {
        if (idx >= n || limit == 0)
            return 0;
        if (dp[idx][canBuy][limit] != -1)
            return dp[idx][canBuy][limit];
        int profit = 0;
        if (canBuy) {
            int buykaro =
                -prices[idx] + solveUsingMemo(idx + 1, 0, limit, prices, dp);
            int ignore = 0 + solveUsingMemo(idx + 1, 1, limit, prices, dp);
            profit = max(buykaro, ignore);
        } else {
            int sellkaro = +prices[idx] +
                           solveUsingMemo(idx + 1, 1, limit - 1, prices, dp);
            int ignore = 0 + solveUsingMemo(idx + 1, 0, limit, prices, dp);
            profit = max(sellkaro, ignore);
        }
        return dp[idx][canBuy][limit] = profit;
    }
    int solveUsingBottomUp(int k,vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(
            n + 1, vector<vector<int>>(2, vector<int>(3, 0)));
        for (int idx = n - 1; idx >= 0; idx--) {
            for (int canBuy = 0; canBuy <= 1; canBuy++) {
                for (int limit = 1; limit <= k; limit++) {
                    int profit = 0;
                    if (canBuy) {
                        int buykaro = -prices[idx] + dp[idx + 1][0][limit];
                        int ignore = 0 + dp[idx + 1][1][limit];
                        profit = max(buykaro, ignore);
                    } else {
                        int sellkaro = +prices[idx] + dp[idx + 1][1][limit - 1];
                        int ignore = 0 + dp[idx + 1][0][limit];
                        profit = max(sellkaro, ignore);
                    }
                    dp[idx][canBuy][limit] = profit;
                }
            }
        }
        return dp[0][1][2];
    }
    int solveUsingSpaceOptmised(int k,vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> curr(2, vector<int>(k+1, 0));
        vector<vector<int>> next(2, vector<int>(k+1, 0));
        for (int idx = n - 1; idx >= 0; idx--) {
            for (int canBuy = 0; canBuy <= 1; canBuy++) {
                for (int limit = 1; limit <= k; limit++) {
                    int profit = 0;
                    if (canBuy) {
                        int buykaro = -prices[idx] + next[0][limit];
                        int ignore = 0 + next[1][limit];
                        profit = max(buykaro, ignore);
                    } else {
                        int sellkaro = +prices[idx] + next[1][limit - 1];
                        int ignore = 0 + next[0][limit];
                        profit = max(sellkaro, ignore);
                    }
                    curr[canBuy][limit] = profit;
                }
            }
            next = curr;
        }
        return next[1][k];
    }
    int maxProfit(int k, vector<int>& prices) {
        n = prices.size();
        int canBuy = 1; // 1:allowed and 0:not allowed
        vector<vector<vector<int>>> dp(
            n + 1, vector<vector<int>>(2, vector<int>(k+1, -1)));
        // return solveUsingMemo(0, 1, k, prices, dp);
        return solveUsingSpaceOptmised(k,prices);
    }
};