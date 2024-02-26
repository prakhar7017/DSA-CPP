class Solution {
public:
    int solve(vector<int>& nums, int target,int index,map<pair<int,int>,int>&dp){
        // basecase
        if(index>=nums.size()){
            return target==0 ? 1 : 0;
        }
        if(dp.find({index,target})!=dp.end()){
            return dp[{index,target}];
        }
        int op1_plus=solve(nums,target-nums[index],index+1,dp);
        int op2_minus=solve(nums,target+nums[index],index+1,dp);
        return dp[{index,target}]=op1_plus+op2_minus;
    }
    int solveTab(vector<int>& nums, int target){
        map<pair<int,int>,int>dp;
        dp[{nums.size(),0}]=1;
        int total=accumulate(nums.begin(),nums.end(),0);
        for(int i=nums.size()-1;i>=0;i--){
            for(int sum=-total;sum<=total;sum++){
                int op1_plus=dp.find({i+1,sum-nums[i]})!=dp.end() ? dp[{i+1,sum-nums[i]}] : 0 ;      //solve(nums,target-nums[index],index+1,dp);
                int op2_minus=dp.find({i+1,sum+nums[i]})!=dp.end() ? dp[{i+1,sum+nums[i]}] : 0 ;  //solve(nums,target+nums[index],index+1,dp);
                dp[{i,sum}]=op1_plus+op2_minus;
            }
        }
        return dp[{0,target}];

    }
    int findTargetSumWays(vector<int>& nums, int target) {
        //map<pair<int,int>,int>dp;
        //return solve(nums,target,0,dp);
        return solveTab(nums,target);
    }
};