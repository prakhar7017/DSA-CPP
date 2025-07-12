class Solution {
public:
    int solve(int index, int end, vector<int>& nums, vector<int>& dp) {
        if (index > end)
            return 0;
        if (dp[index] != -1)
            return dp[index];

        int include = nums[index] + solve(index + 2, end, nums, dp);
        int exclude = 0 + solve(index + 1, end, nums, dp);

        return dp[index] = max(include, exclude);
    }
    int solveUsingTab(int start,int end,vector<int>&nums){
        int len=end-start+1;
        if(len==0) return 0;
        vector<int>dp(len+2,0);
        dp[end]=nums[end];
        for(int i=end-1;i>=start;i--){
            int include=nums[i]+dp[i+2];
            int exclude=0+dp[i+1];

            dp[i]=max(include,exclude);
        }
        return dp[start];
    }
    int solveUsingSpace(int start,int end,vector<int>&nums){
        int prev=nums[end];
        int next=0;
        int curr;
        for(int i=end-1;i>=start;i--){
            int include=nums[i]+next;
            int exclude=0+prev;
            curr=max(include,exclude);
            next=prev;
            prev=curr;
        }
        return prev;

    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        if (n == 2)
            return max(nums[0], nums[1]);

        // Case 1: Rob from house 0 to n-2
        int take0thHouse = solveUsingSpace(0,n-2,nums);

        // Case 2: Rob from house 1 to n-1
        int take1stHouse = solveUsingSpace(1,n-1,nums);

        return max(take0thHouse, take1stHouse);
    }
};