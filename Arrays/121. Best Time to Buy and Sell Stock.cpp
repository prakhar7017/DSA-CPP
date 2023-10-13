class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minCp=INT_MAX;
        int maxProfit=0;
        for(int i=0;i<prices.size();i++){
            minCp=min(minCp,prices[i]);
            int profit=prices[i]-minCp;
            maxProfit=max(maxProfit,profit);
        }
        return maxProfit;
    }
// };

// time complexity:O(n) space complexity:O(1)

// --------------------------------------------------------------------------------------

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int>aux(n);
        int maxSp=INT_MIN;
        int maxProfit=0;
        for(int i=n-1;i>=0;i--){
            if(prices[i]>maxSp){
                maxSp=prices[i];
            }
            aux[i]=maxSp;
        }

        for(int i=0;i<n;i++){
            int profit=abs(prices[i]-aux[i]);
            maxProfit= profit > maxProfit ? profit : maxProfit ;
        }

        return maxProfit;
    }
};

// time complexity:O(n) space complexity:O(n) 