class Solution {
public:
    int n;
    bool solveUsingRec(int idx,int target,vector<int>& nums,vector<vector<int>>&dp){
        if(target == 0) return true;
        if(idx>=n) return false;
        if(dp[idx][target]!=-1) return dp[idx][target];
        bool include = false;
        if(nums[idx]<=target) include = solveUsingRec(idx+1,target-nums[idx],nums,dp);
        bool exclude = solveUsingRec(idx+1,target,nums,dp);
        return dp[idx][target]=include || exclude;
    }
    bool canPartition(vector<int>& nums) {
        n = nums.size();
        int sum = accumulate(begin(nums),end(nums),0);
        if(sum%2!=0) return false;
        int target = sum/2;
        vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
        return solveUsingRec(0,target,nums,dp);   
    }
};