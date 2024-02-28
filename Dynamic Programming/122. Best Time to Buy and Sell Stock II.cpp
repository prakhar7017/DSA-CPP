class Solution {
public:
    int solve(vector<int>& prices,int i,int buy,vector<vector<int>>&dp){
        //base case
        if(i>=prices.size()){
            return 0;
        }
        if(dp[i][buy]!=-1){
            return dp[i][buy];
        }
        int profit=INT_MIN;
        if(buy){
            int letsBuy=-prices[i]+solve(prices,i+1,0,dp);
            int letsIgnore=0+solve(prices,i+1,1,dp);
            profit=max(letsBuy,letsIgnore);
        }else{
            int letsSell=prices[i]+solve(prices,i+1,1,dp);
            int letsIgnore=solve(prices,i+1,0,dp);
            profit=max(letsSell,letsIgnore);
        }
        return dp[i][buy]=profit;
    }

    int solveTab(vector<int>& prices){
        int n=prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,0));
        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<=1;buy++){
                int profit=INT_MIN;
                if(buy){
                    int letsBuy=-prices[i]+dp[i+1][0];//solve(prices,i+1,0,dp);
                    int letsIgnore=0+dp[i+1][1];//solve(prices,i+1,1,dp);
                    profit=max(letsBuy,letsIgnore);
                }else{
                    int letsSell=prices[i]+dp[i+1][1];//solve(prices,i+1,1,dp);
                    int letsIgnore=0+dp[i+1][0];//solve(prices,i+1,0,dp);
                    profit=max(letsSell,letsIgnore);
                }
                dp[i][buy]=profit;
            }
        }
        return dp[0][1];
    }
    int spaceOptmized(vector<int>& prices){
        int n=prices.size();
        vector<int>currRow(2,0);
        vector<int>nextRow(2,0);
        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<=1;buy++){
                int profit=INT_MIN;
                if(buy){
                    int letsBuy=-prices[i]+nextRow[0];//solve(prices,i+1,0,dp);
                    int letsIgnore=0+nextRow[1];//solve(prices,i+1,1,dp);
                    profit=max(letsBuy,letsIgnore);
                }else{
                    int letsSell=prices[i]+nextRow[1];//solve(prices,i+1,1,dp);
                    int letsIgnore=0+nextRow[0];//solve(prices,i+1,0,dp);
                    profit=max(letsSell,letsIgnore);
                }
                currRow[buy]=profit;
            }
            // shifitng
            nextRow=currRow;
        }
        return nextRow[1];
    }
    int maxProfit(vector<int>& prices) {
        // int n=prices.size();
        // vector<vector<int>>dp(n+1,vector<int>(2,-1));
        // return solveTab(prices,0,1,dp);
        return spaceOptmized(prices);





        // int profit=0;
        // for(int i=0;i<prices.size();i++){
        //     if(i>0 && prices[i]>prices[i-1]){
        //         profit+=prices[i]-prices[i-1];
        //     }
        // }
        // return profit;
    }
};


// itrative Approach , Fastest Approach 
int maxProfit(vector<int>& prices) {
        int profit=0;
        for(int i=0;i<prices.size();i++){
            if(i>0 && prices[i]>prices[i-1]){
                profit+=prices[i]-prices[i-1];
            }
        }
        return profit;
    }