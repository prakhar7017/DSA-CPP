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


vector<pair<int,string>>mp={{1000000000,"Billion"},{100000,"Million"},{1000,"Thousand"},{100,"Hundred"},{90,"Ninety"},{80,"Eighty"},{70,"Seventy"},{60,"Sixty"},{50,"Fifty"},{40,"Forty"},{30,"Thirty"},{20,"Twenty"},{19,"Nineteen"},{18,"Eighteen"},{17,"Seventeen"},{16,"Sixteen"},{15,"Fifteen"},{14,"Fourteen"},{13,"Thirteen"},{12,"Twelve"},{11,"Eleven"},{10,"Ten"},{9,"Nine"},{8,"Eight"},{7,"Seven"},{6,"Six"},{5,"Five"},{4,"Four"},{3,"Three"},{2,"Two"},{1,"One"}};