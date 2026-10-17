class Solution {
public:
    int n;
    int solveUsingMemo(int curr,int prev,vector<int>& nums,vector<vector<int>>&dp){
        if(curr>=n) return 0;
        if(dp[curr][prev+1]!=-1) return dp[curr][prev+1];
        int include =0;
        if(prev == -1 || nums[prev]<nums[curr]){
            include  = 1 + solveUsingMemo(curr+1,curr,nums,dp);
        }
        int exclude = 0 + solveUsingMemo(curr+1,prev,nums,dp);
        return dp[curr][prev+1]=max(include,exclude);
    }
    int lengthOfLIS(vector<int>& nums) {
        n = nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solveUsingMemo(0,-1,nums,dp);
    }
};