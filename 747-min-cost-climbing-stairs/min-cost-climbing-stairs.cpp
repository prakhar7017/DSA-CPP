class Solution {
public:
    int solveUsingDP(int idx,vector<int>& cost,vector<int>&dp){
        if(idx>=cost.size()) return 0;
        if(dp[idx]!=-1) return dp[idx];
        int onestep = cost[idx]+solveUsingDP(idx+1,cost,dp);
        int twostep = cost[idx]+solveUsingDP(idx+2,cost,dp);
        return dp[idx]=min(onestep,twostep);
    }
    int solveUsingBottomUp(vector<int>& cost){
        int n = cost.size();
        if(n == 2) return min(cost[0],cost[1]);

        for(int i=2;i<n;i++){
            cost[i] = cost[i]+min(cost[i-1],cost[i-2]);
        }
        return 0 + min(cost[n-1],cost[n-2]);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int>dp(n+1,-1);
        return solveUsingBottomUp(cost);
    }
};