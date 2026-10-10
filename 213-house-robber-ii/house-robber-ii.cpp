class Solution {
public:
    int solveUsingDp(int idx, int end, vector<int>& nums, vector<int>& dp) {
        if (idx > end)
            return 0;
        if (dp[idx] != -1)
            return dp[idx];
        int include = nums[idx] + solveUsingDp(idx + 2, end, nums, dp);
        int exclude = solveUsingDp(idx + 1, end, nums, dp);
        return dp[idx] = max(include, exclude);
    }
    int solveUsingBottomUp(int idx, int end, vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n + 2, 0);

        for (int i = end; i >= idx; i--) {
            int include = nums[i] + dp[i + 2];
            int exclude = dp[i + 1];
            dp[i] = max(include, exclude);
        }
        return dp[idx];
    }
    int solveUsingSpaceOptimised(int idx, int end, vector<int>& nums) {
        int n = nums.size();
        int next2=0;
        int next1=0;

        for (int i = end; i >= idx; i--) {
            int include = nums[i] + next2;
            int exclude = next1;
            int curr = max(include, exclude);
            next2=next1;
            next1=curr;
        }
        return next1;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        if (n == 2)
            return max(nums[0], nums[1]);
        vector<int> dp1(n + 1, -1);
        vector<int> dp2(n + 1, -1);
        return max(solveUsingSpaceOptimised(0, n - 2, nums),
                   solveUsingSpaceOptimised(1, n - 1, nums));
    }
};