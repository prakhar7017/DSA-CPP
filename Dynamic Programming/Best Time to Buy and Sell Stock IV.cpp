class Solution {
public:
    int solve(vector<int>& prices,int i,int buy,int limit,vector<vector<vector<int>>>&dp){
        //base case
        if(i>=prices.size() || limit==0){
            return 0;
        }
        if(dp[i][buy][limit]!=-1){
            return dp[i][buy][limit];
        }
        int profit=INT_MIN;
        if(buy){
            int letsBuy=-prices[i]+solve(prices,i+1,0,limit,dp);
            int letsIgnore=0+solve(prices,i+1,1,limit,dp);
            profit=max(letsBuy,letsIgnore);
        }else{
            int letsSell=prices[i]+solve(prices,i+1,1,limit-1,dp);
            int letsIgnore=solve(prices,i+1,0,limit,dp);
            profit=max(letsSell,letsIgnore);
        }
        return dp[i][buy][limit]=profit;
    }
     int solveTab(vector<int>& prices,int k){
       int n=prices.size();
        vector<vector<vector<int>>>dp(n+1,
                                vector<vector<int>>(2,
                                                        vector<int>(k+1,0)));
        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<=1;buy++){
               for(int limit=k;limit>=1;limit--){
                   int profit=INT_MIN;
                    if(buy){
                        int letsBuy=-prices[i]+dp[i+1][0][limit];//solve(prices,i+1,0,dp);
                        int letsIgnore=0+dp[i+1][1][limit];//solve(prices,i+1,1,dp);
                        profit=max(letsBuy,letsIgnore);
                    }else{
                        int letsSell=prices[i]+dp[i+1][1][limit-1];//solve(prices,i+1,1,dp);
                        int letsIgnore=0+dp[i+1][0][limit];//solve(prices,i+1,0,dp);
                        profit=max(letsSell,letsIgnore);
                    }
                    dp[i][buy][limit]=profit;
               }
            }
        }
        return dp[0][1][k];
    }
    int maxProfit(int k,vector<int>& prices) {
        // int n=prices.size();
        // int limit=k;
        // vector<vector<vector<int>>>dp(n+1,
        //                         vector<vector<int>>(2,
        //                                                 vector<int>(limit+1,-1)));

        return solveTab(prices,k);
    }
};