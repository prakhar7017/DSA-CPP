class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int maxProfit=0;
        int minPrice=prices[0];
        for(int day=1;day<n;day++){
            int todayPrice=prices[day];
            int todayProfit=todayPrice-minPrice;
            maxProfit=max(maxProfit,todayProfit);
            minPrice=min(minPrice,todayPrice);
        }
        return maxProfit;
    }
};