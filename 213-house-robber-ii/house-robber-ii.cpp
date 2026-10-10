class Solution {
public:
    int solveUsingDp(int idx,int end,vector<int>& nums,vector<int>&dp){
        if(idx>end) return 0;
        if(dp[idx]!=-1) return dp[idx];
        int include = nums[idx] + solveUsingDp(idx+2,end,nums,dp);
        int exclude = solveUsingDp(idx+1,end,nums,dp);
        return dp[idx]=max(include,exclude);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        if(n==2) return max(nums[0],nums[1]);
        vector<int>dp1(n+1,-1);
        vector<int>dp2(n+1,-1);
        return max(solveUsingDp(0,n-2,nums,dp1),solveUsingDp(1,n-1,nums,dp2));
    }
};