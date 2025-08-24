class Solution {
public:
    int solveUsingRec(int index, int buy,int fee, vector<int>& prices,
                      vector<vector<int>>& dp) {
        if (index >= prices.size())
            return 0;

        if (dp[index][buy] != -1)
            return dp[index][buy];

        int profit = 0;
        if (buy) {
            profit =
                max(-prices[index] + solveUsingRec(index + 1, 0,fee, prices, dp),
                    0 + solveUsingRec(index + 1, 1,fee, prices, dp));
        } else {
            profit =
                max(-fee+prices[index] + solveUsingRec(index + 1, 1,fee, prices, dp),
                    0 + solveUsingRec(index + 1, 0,fee, prices, dp));
        }
        return dp[index][buy] = profit;
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return solveUsingRec(0,1,fee,prices,dp);
    }
};