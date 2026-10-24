class Solution {
public:
    int n,offset;
    int solveUsingMemo(int idx,int sum,int target,vector<int>& nums,vector<vector<int>>&dp){
        if(idx == n){
            if(sum == target) return 1;
            return 0;
        }
        if(dp[idx][sum+offset]!=-1) return dp[idx][sum+offset]; 
        int pos = solveUsingMemo(idx+1,sum+nums[idx],target,nums,dp);
        int neg = solveUsingMemo(idx+1,sum-nums[idx],target,nums,dp);
        return dp[idx][sum+offset]= pos+neg;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        n = nums.size();
        offset = accumulate(begin(nums),end(nums),0);
        if (abs(target) > offset) {
            return 0;
        }
        vector<vector<int>>dp(n+1,vector<int>(2*offset+1,-1));
        return solveUsingMemo(0,0,target,nums,dp);
    }
};