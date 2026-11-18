class Solution {
public:
    int solveUsingRecursion(vector<int>& nums, int idx, vector<int>& dp) {
        if (idx >= nums.size())
            return 0;
        if (dp[idx] != -1)
            return dp[idx];
        int include = nums[idx] + solveUsingRecursion(nums, idx + 2, dp);
        int exclude = 0 + solveUsingRecursion(nums, idx + 1, dp);
        return dp[idx] = max(include, exclude);
    }
    int solveUsingBottomUp(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n + 2, 0);
        for (int idx = n - 1; idx >= 0; idx--) {
            int include = nums[idx] +dp[idx + 2];
            int exclude = 0 + dp[idx + 1];
            dp[idx] = max(include, exclude);
        }
        return dp[0];
    }
    int solveUsingSpaceOp(vector<int>& nums) {
        int n = nums.size();
        int next1=0;
        int next2=0;
        for (int idx = n - 1; idx >= 0; idx--) {
            int include = nums[idx] +next2;
            int exclude = 0 + next1;
            int curr = max(include, exclude);
            next2=next1;
            next1=curr;
        }
        return next1;
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size() + 1, -1);
        return solveUsingSpaceOp(nums);
    }
};