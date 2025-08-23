class Solution {
public:
    void solveUsingRec(int iday,int &minPrice,int &maxProfit,vector<int>&prices){
        if(iday>=prices.size()) return;
        if(prices[iday]<minPrice) minPrice=prices[iday];
        int todayProfit=prices[iday]-minPrice;
        if(todayProfit>maxProfit) maxProfit=todayProfit;
        solveUsingRec(iday+1,minPrice,maxProfit,prices);

    }
    int maxProfit(vector<int>& prices) {
        int minPrice=INT_MAX;
        int maxProfit=INT_MIN;
        solveUsingRec(0,minPrice,maxProfit,prices);
        return maxProfit;
    }
};