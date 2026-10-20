class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int mini = prices[0];
        int profit = 0;
        for(int sellDay = 1;sellDay<n;sellDay++){
            int ajjKadiff = prices[sellDay]-mini;
            profit = max(profit,ajjKadiff);
            mini = min(mini,prices[sellDay]);
        }
        return profit;
    }
};