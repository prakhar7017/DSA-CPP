class Solution {
public:
    int solve(int index,vector<int>&nums,vector<int>&dp){
        // basecase
        if(index>=nums.size()) return 0;
        if(dp[index]!=-1) return dp[index];
        int include=nums[index]+solve(index+2,nums,dp);
        int exclude=0+solve(index+1,nums,dp);

        return dp[index]=max(include,exclude);
    }
    int solveUsingTab(vector<int>&nums){
        int n=nums.size();
        vector<int>dp(n+1,0);
        dp[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            int include=nums[i]+dp[i+2];
            int exclude=0+dp[i+1];
            dp[i]=max(include,exclude);
        }
        return dp[0];
    }
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size()+1,-1);
        // return solve(0,nums,dp);
        return solveUsingTab(nums);
    }
};