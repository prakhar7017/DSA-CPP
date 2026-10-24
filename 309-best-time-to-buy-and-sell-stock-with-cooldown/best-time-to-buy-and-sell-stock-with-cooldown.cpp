class Solution {
public:
    int n;
    int solveUsingMemo(int idx,int canBuy,vector<int>&prices,vector<vector<int>>&dp){
        if(idx>=n) return 0;
        if(dp[idx][canBuy]!=-1) return dp[idx][canBuy];
        int profit = 0;
        if(canBuy){
            int buy = -prices[idx]+solveUsingMemo(idx+1,0,prices,dp);
            int ignore = 0 + solveUsingMemo(idx+1,1,prices,dp);
            profit = max(buy,ignore);
        }else{
            int sell = prices[idx] + solveUsingMemo(idx+2,1,prices,dp);
            int ignore = 0 + solveUsingMemo(idx+1,0,prices,dp);
            profit = max(sell,ignore);
        }
        return dp[idx][canBuy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        n = prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,-1));
        return solveUsingMemo(0,1,prices,dp);
    }
};