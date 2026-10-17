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
    int solveUsingBottomUp(vector<int>& nums){
        int n = nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        for(int curr = n-1;curr>=0;curr--){
            for(int prev = n-1;prev>=-1;prev--){
                int include =0;
                if(prev == -1 || nums[prev]<nums[curr]){
                    include = 1+dp[curr+1][curr+1];
                }
                int exclude = dp[curr+1][prev+1];
                dp[curr][prev+1]=max(include,exclude);
            }
        }
        return dp[0][0];
    }
     int solveUsingSpaceOptimised(vector<int>& nums){
        int n = nums.size();
        vector<int>currRow(n+1,0);
        vector<int>nextRow(n+1,0);
        for(int curr = n-1;curr>=0;curr--){
            for(int prev = n-1;prev>=-1;prev--){
                int include =0;
                if(prev == -1 || nums[prev]<nums[curr]){
                    include = 1+nextRow[curr+1];
                }
                int exclude = nextRow[prev+1];
                currRow[prev+1]=max(include,exclude);
            }
            nextRow = currRow;
        }
        return nextRow[0];
    }
    int solveUsingBS(vector<int>& nums){
        int n = nums.size();
        if(n==0) return 0;
        vector<int>ans;
        ans.push_back(nums[0]);
        for(int i=1;i<n;i++){
            if(nums[i]>ans.back()){
                ans.push_back(nums[i]);
            }else{
                int index = lower_bound(begin(ans),end(ans),nums[i]) - ans.begin();
                ans[index]=nums[i];
            }
        }
        return ans.size();
    }
    int lengthOfLIS(vector<int>& nums) {
        n = nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solveUsingBS(nums);
    }
};