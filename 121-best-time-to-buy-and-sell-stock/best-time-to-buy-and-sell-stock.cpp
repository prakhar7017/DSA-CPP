class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int>t(n);
        int maxSp=INT_MIN;

        for(int i=n-1;i>=0;i--){
            if(prices[i]>maxSp)maxSp=prices[i];
            t[i]=maxSp;
        }
        int maxProfit=0;
        for(int i=0;i<n;i++){
            int profit=abs(prices[i]-t[i]);
            if (profit>maxProfit){
                maxProfit=profit;
            }
        }

        return maxProfit;
    }
};