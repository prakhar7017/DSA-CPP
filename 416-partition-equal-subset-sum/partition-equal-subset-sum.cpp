class Solution {
public:
    int n;
    bool solve(int idx,int x,vector<int>&nums,vector<vector<int>>&dp){
        if(x == 0) return true;
        if(idx>=n) return false;
        if(dp[idx][x]!=-1) return dp[idx][x];
        bool include =false;
        if(x>=nums[idx]){
            include = solve(idx+1,x-nums[idx],nums,dp);
        }
        bool exclude = solve(idx+1,x,nums,dp);
        return dp[idx][x]=include||exclude;
    }
    bool canPartition(vector<int>& nums) {
        n = nums.size();
        int s = accumulate(begin(nums),end(nums),0);
        if(s%2!=0) return false;

        int x = s/2;
        vector<vector<int>>dp(n+1,vector<int>(s+1,-1));
        return solve(0,x,nums,dp); 
    }
};