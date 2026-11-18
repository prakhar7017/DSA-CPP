class Solution {
public:
    int solveUsingRecursion(vector<int>&nums,int idx,vector<int>&dp){
        if(idx>=nums.size()) return 0;
        if(dp[idx]!=-1) return dp[idx];
        int include =nums[idx]+solveUsingRecursion(nums,idx+2,dp);
        int exclude =0+solveUsingRecursion(nums,idx+1,dp);
        return dp[idx]=max(include,exclude);

    }
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size()+1,-1);
        return solveUsingRecursion(nums,0,dp);
    }
};