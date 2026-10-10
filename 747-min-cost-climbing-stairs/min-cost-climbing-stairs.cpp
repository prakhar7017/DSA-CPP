class Solution {
public:
    int solveUsingDP(int idx,vector<int>& cost,vector<int>&dp){
        if(idx>=cost.size()) return 0;
        if(dp[idx]!=-1) return dp[idx];
        int onestep = cost[idx]+solveUsingDP(idx+1,cost,dp);
        int twostep = cost[idx]+solveUsingDP(idx+2,cost,dp);
        return dp[idx]=min(onestep,twostep);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int>dp(n+1,-1);
        return min(solveUsingDP(0,cost,dp),solveUsingDP(1,cost,dp));
    }
};