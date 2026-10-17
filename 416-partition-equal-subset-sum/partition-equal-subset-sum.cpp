class Solution {
public:
    int n;
    bool solve(int idx, int x, vector<int>& nums, vector<vector<int>>& dp) {
        if (x == 0)
            return true;
        if (idx >= n)
            return false;
        if (dp[idx][x] != -1)
            return dp[idx][x];
        bool include = false;
        if (x >= nums[idx]) {
            include = solve(idx + 1, x - nums[idx], nums, dp);
        }
        bool exclude = solve(idx + 1, x, nums, dp);
        return dp[idx][x] = include || exclude;
    }
    bool solveUsingTab(vector<int>& nums) {
        int s = accumulate(begin(nums), end(nums), 0);
        if (s % 2 != 0)
            return false;
        int target = s / 2;
        vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));

        for (int i = 0; i <= n; i++) {
            dp[i][0] = true;
        }

        for (int idx = n - 1; idx >= 0; idx--) {
            for (int x = 0; x <= target; x++) {
                bool include = false;
                if (x >= nums[idx]) {
                    include = dp[idx + 1][x - nums[idx]];
                }
                bool exclude = dp[idx + 1][x];
                dp[idx][x] = include || exclude;
            }
        }
        return dp[0][target];
    }
    bool solveUsingSpace(vector<int>& nums) {
        int s = accumulate(begin(nums), end(nums), 0);
        if (s % 2 != 0)
            return false;
        int target = s / 2;
        vector<bool>curr(target+1,false);
        vector<bool>next(target+1,false);
        curr[0]=true;
        next[0]=true;

        for (int idx = n - 1; idx >= 0; idx--) {
            for (int x = 0; x <= target; x++) {
                bool include = false;
                if (x >= nums[idx]) {
                    include = next[x - nums[idx]];
                }
                bool exclude = next[x];
                curr[x] = include || exclude;
            }
            next = curr;
        }
        return next[target];
    }
    bool canPartition(vector<int>& nums) {
        n = nums.size();
        int s = accumulate(begin(nums), end(nums), 0);
        if (s % 2 != 0)
            return false;

        int x = s / 2;
        vector<vector<int>> dp(n + 1, vector<int>(s + 1, -1));
        return solveUsingSpace(nums);
    }
};