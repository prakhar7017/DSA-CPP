class Solution {
public:
    int solve(vector<int>& nums,int start,int end,vector<vector<int>>&dp){
        // base case
        if(start==end) return nums[start];
        if(dp[start][end]!=-1) return dp[start][end];
        int includeFirstEle=nums[start]-solve(nums,start+1,end,dp);
        int includeLastEle=nums[end]-solve(nums,start,end-1,dp);
        return dp[start][end]=max(includeFirstEle,includeLastEle);
    }

    int solveTab(vector<int>& nums){
        vector<vector<int>>dp(nums.size()+1,vector<int>(nums.size(),-1));
        for(int i=0;i<nums.size();i++) dp[i][i]=nums[i];
        int i=nums.size();
        for(int start=nums.size()-1;start>=0;start--){
            for(int end=i;end<nums.size();end++){
                int includeFirstEle=nums[start]-dp[start+1][end];//solve(nums,start+1,end,dp);
                int includeLastEle=nums[end]-dp[start][end-1];//solve(nums,start,end-1,dp);
                dp[start][end]=max(includeFirstEle,includeLastEle);
            }
            i--;
        }
        return dp[0][nums.size()-1];
    }
    bool predictTheWinner(vector<int>& nums) {
        // vector<vector<int>>dp(nums.size(),vector<int>(nums.size(),-1));
        // return solve(nums,0,nums.size()-1,dp) >= 0 ;
        return solveTab(nums) >= 0; 
    }
};