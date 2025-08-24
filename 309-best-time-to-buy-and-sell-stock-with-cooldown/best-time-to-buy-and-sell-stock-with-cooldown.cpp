class Solution {
public:
    int solveUsingRec(int index, int buy, vector<int>& prices,vector<vector<int>>& dp) {
        if (index >= prices.size())
            return 0;

        if(dp[index][buy]!=-1) return dp[index][buy];    

        int profit = 0;
        if (buy) {
            profit = max(-prices[index] + solveUsingRec(index + 1, 0, prices,dp),
                         0 + solveUsingRec(index + 1, 1, prices,dp));
        } else {
            profit = max(prices[index] + solveUsingRec(index + 2, 1, prices,dp),
                         0 + solveUsingRec(index + 1, 0, prices,dp));
        }
        return dp[index][buy]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return solveUsingRec(0,1,prices,dp);
    }
};