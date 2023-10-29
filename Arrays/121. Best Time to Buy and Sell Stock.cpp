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


// recursive solution:
class Solution {
    private:
    void maxProfitFind(vector<int>& prices,int i,int &minPrice,int &maxProfit){
        //base case
        if(i>=prices.size()){
            return;
        }
        //processing
        if(prices[i]<minPrice){
            minPrice=prices[i];
        }
        int todayProfit=prices[i]-minPrice;
        if(todayProfit>maxProfit){
            maxProfit=todayProfit;
        }
        //re calls
        maxProfitFind(prices,i+1,minPrice,maxProfit);
    }
public:
    int maxProfit(vector<int>& prices) {
        int minPrice=INT_MAX;
        int maxProfit=INT_MIN;
        maxProfitFind(prices,0,minPrice,maxProfit);
        return maxProfit;
    }
};

// time comeplexity:O(n) space complexity:O(n)