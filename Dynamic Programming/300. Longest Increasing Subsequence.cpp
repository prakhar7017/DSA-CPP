class Solution {
public:
    int solveUsingRec(vector<int>& nums,int prev,int curr,vector<vector<int>>&dp){
        // base case
        if(curr>=nums.size()){
            return 0;
        }
        if(dp[curr][prev+1]!=-1){
            return dp[curr][prev+1];
        }
        int include=0;
        if(prev==-1 || nums[curr] > nums[prev]){
            include=1+solveUsingRec(nums,curr,curr+1,dp);
        }
        int exclude=0+solveUsingRec(nums,prev,curr+1,dp);

        return dp[curr][prev+1]=max(include,exclude);
    }
    int solveUsingTab(vector<int>& nums){
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0)); //also base case analaysis
        for(int curr=n-1;curr>=0;curr--){
            for(int prev=curr-1;prev>=-1;prev--){
                int include=0;
                if(prev==-1 || nums[curr] > nums[prev]){
                    include=1+dp[curr+1][curr+1];
                }
                int exclude=0+dp[prev+1][curr+1];

                dp[prev+1][curr]=max(include,exclude);
            }
        }
        return dp[0][0];
    }
    int solveUsingTabSO(vector<int>& nums){
        int n=nums.size();
        vector<int>currRow(n+1,0);
        vector<int>nextRow(n+1,0);
        for(int curr=n-1;curr>=0;curr--){
            for(int prev=curr-1;prev>=-1;prev--){
                int include=0;
                if(prev==-1 || nums[curr] > nums[prev]){
                    include=1+nextRow[curr+1];
                }
                int exclude=0+nextRow[prev+1];

                currRow[prev+1]=max(include,exclude);
            }
            // shifitng
            nextRow=currRow;
        }
        return nextRow[0];
    }

    // most optimized solution
    int solveUsingBS(vector<int>& nums){
        int n=nums.size();
        vector<int>ans;
        ans.push_back(nums[0]);
        for(int i=1;i<n;i++){
            if(nums[i]>ans.back()){
                ans.push_back(nums[i]);
            }else{
                // menas bada number exist , ana vala element ans ka last element sa chota hh 
                int index=lower_bound(ans.begin(),ans.end(),nums[i])-ans.begin();
                ans[index]=nums[i];
            }
        }
        return ans.size();
    }
    int lengthOfLIS(vector<int>& nums) {
        // int n=nums.size();
        // vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        // int prev=-1;
        // int curr=0;
        return solveUsingBS(nums);

    }
};










// optimized solution
class Solution {
public:
    int lengthOfLIS(std::vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        int n = nums.size();
        std::vector<int> dp(n, 1);

        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    dp[i] = std::max(dp[i], dp[j] + 1);
                }
            }
        }

        return *std::max_element(dp.begin(), dp.end());
    }
};