class Solution {
public:
    // int solveUsingBottomUp(vector<int>& nums) {
    //     int n = nums.size();
    //     int

    //         for (int i = n - 1; i >= 0; i--) {
    //         int include = nums[i] + dp[i + 2];
    //         int exclude = dp[i + 1];
    //         dp[i] = max(include, exclude);
    //     }
    //     return dp[0];
    // }
    int spaceOptimised(vector<int>& nums) {
        int n = nums.size();
        int next2 = 0;
        int next1 = 0;

        for (int i = n - 1; i >= 0; i--) {
            int include = nums[i] + next2;
            int exclude = next1;
            int curr = max(include, exclude);
            next2 = next1;
            next1 = curr;
        }
        return next1;
    }
    int solveUsingDp(int idx, vector<int>& dp, vector<int>& nums) {
        if (idx >= nums.size())
            return 0;
        if (dp[idx] != -1)
            return dp[idx];
        int include = nums[idx] + solveUsingDp(idx + 2, dp, nums);
        int exclude = solveUsingDp(idx + 1, dp, nums);
        return dp[idx] = max(include, exclude);
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size() + 1, -1);
        return spaceOptimised(nums);
    }
};