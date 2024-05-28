/*
    Minimum cost to fill given weight in a bag
    Given an array cost[] of positive integers of size n and an integer w, where cost[i] represents the cost of an i kg packet of oranges, the task is to find the minimum cost to buy exactly w kg of oranges. The cost array has a 1-based indexing. If buying exactly w kg of oranges is impossible, then return -1.
    Note:
    1. cost[i] = -1 means that i kg packet of orange is unavailable.
    2. It may be assumed that there is an infinite supply of all available packet types.

*/

class Solution {
  public:
    int solve(int idx,int w,vector<int>&cost,vector<vector<int>>&dp){
        // base case
        if(idx>=cost.size() || w<0) return 1e9;
        if(w==0) return 0;
        if(dp[w][idx]!=-1){
            return dp[w][idx];
        }
        int include=1e9;
        if(cost[idx]!=-1 && w-(idx+1)>=0){
            include=cost[idx]+solve(idx,w-(idx+1),cost,dp);
        }
        int exclude=0+solve(idx+1,w,cost,dp);
        
        return dp[w][idx]=min(include,exclude);
    }
    
    int solveUsingTab(vector<int>&cost,int w){
        int n=cost.size();
        
        vector<vector<int>>dp(n+1,vector<int>(w+1,1e9));
        for(int i=0;i<=n;i++){
            dp[i][0]=0;
        }
        
        for(int idx=n-1;idx>=0;--idx){
            for(int wt=0;wt<=w;wt++){
                int include=1e9;
                if(cost[idx]!=-1 && wt-(idx+1)>=0){
                    include=cost[idx]+dp[idx][wt-(idx+1)];
                }
                int exclude=0+dp[idx+1][wt];
                dp[idx][wt]=min(include,exclude);
            }
        }
        return dp[0][w];
    }
    int minimumCost(int n, int w, vector<int> &cost) {
        int index=0;
        vector<vector<int>>dp(w+1,vector<int>(n+1,-1));
        // int ans=solveUsingTab(index,w,cost,dp);
        
        int ans=solveUsingTab(cost,w);
        return ans>=INT_MAX ? -1 : ans;
        
    }
};

// time complexity: O(n*w)
// space complexity: O(n*w)
