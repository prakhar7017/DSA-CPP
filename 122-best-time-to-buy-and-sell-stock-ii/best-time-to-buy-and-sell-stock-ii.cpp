class Solution {
public:
    int solveSpaceOptimized1(vector<int>& prices) {
        int n = prices.size();
        int nextBuy, nextNotBuy, currBuy, currNotBuy;
        nextBuy = nextNotBuy = 0;

        for (int index = n - 1; index >= 0; index--) {
            currBuy = max(-prices[index] + nextNotBuy, 0 + nextBuy);
            currNotBuy = max(prices[index] + nextBuy, 0 + nextNotBuy);
            nextBuy = currBuy;
            nextNotBuy = currNotBuy;
        }
        return nextBuy;
    }
    int maxProfit(vector<int>& prices) {
        return solveSpaceOptimized1(prices);
    }
};