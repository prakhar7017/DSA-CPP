class Solution {
public:
    int solveUsingRec(int idx,int prev,vector<int>& nums,vector<vector<int>>& dp){
        // basecase
        if(idx>=nums.size()) return 0;

        if(dp[idx][prev+1]!=-1) return dp[idx][prev+1];

        //take idx element
        int take=0;
        if(prev==-1 || nums[prev]<nums[idx]){
            take=1+solveUsingRec(idx+1,idx,nums,dp);
        }

        int notTake=0;
        notTake=0+solveUsingRec(idx+1,prev,nums,dp);
        return dp[idx][prev+1]=max(take,notTake);
    }

    int solveUsingBottomUp(vector<int>& nums){
        int n=nums.size();
        vector<int>dp(n,1);
        int maxLis=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i]){
                    dp[i]=max(dp[i],dp[j]+1);
                    maxLis=max(maxLis,dp[i]);
                }
            }
        }
        return maxLis;
    }

    int solveUsingBinarySearch(vector<int>& nums){
        int n=nums.size();
        vector<int>sorted;
        for(int i=0;i<n;i++){
            auto it=lower_bound(sorted.begin(),sorted.end(),nums[i]);
            if(it==sorted.end()){
                sorted.push_back(nums[i]);
            }else{
                *it=nums[i];
            }
        }
        return sorted.size();
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        int prev=-1;
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        // return solveUsingRec(0,prev,nums,dp);
        // return solveUsingBottomUp(nums);
        return solveUsingBinarySearch(nums);
    }
};