class Solution {
public:
    int solveUsingDp(int idx,vector<int>&dp,vector<int>&nums){
        if(idx>=nums.size()) return 0;
        if(dp[idx]!=-1) return dp[idx];
        int include = nums[idx] + solveUsingDp(idx+2,dp,nums);
        int exclude = solveUsingDp(idx+1,dp,nums);
        return  dp[idx]=max(include,exclude);
    }
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size()+1,-1);
        return solveUsingDp(0,dp,nums);
    }
};