class Solution {
public:
    int n;
    bool solveUsingRec(int idx, int target, vector<int>& nums,
                       vector<vector<int>>& dp) {
        if (target == 0)
            return true;
        if (idx >= n)
            return false;
        if (dp[idx][target] != -1)
            return dp[idx][target];
        bool include = false;
        if (nums[idx] <= target)
            include = solveUsingRec(idx + 1, target - nums[idx], nums, dp);
        bool exclude = solveUsingRec(idx + 1, target, nums, dp);
        return dp[idx][target] = include || exclude;
    }
    bool solveUsingTab(vector<int>& nums) {
        int sum = accumulate(begin(nums), end(nums), 0);
        if (sum % 2 != 0)
            return false;
        int x = sum / 2;
        vector<vector<bool>> dp(n + 1, vector<bool>(x + 1, false));
        for (int i = 0; i <= n; i++) {
            dp[i][0] = true;
        }
        for (int idx = n - 1; idx >= 0; idx--) {
            for (int target = 0; target <= x; target++) {
                bool include = false;
                if (nums[idx] <= target)
                    include =dp[idx + 1][target - nums[idx]];
                bool exclude = dp[idx + 1][target];
                dp[idx][target] = include || exclude;
            }
        }
        return dp[0][x];
    }
    bool solveUsingSpace(vector<int>& nums) {
        int sum = accumulate(begin(nums), end(nums), 0);
        if (sum % 2 != 0)
            return false;
        int x = sum / 2;
        vector<bool>curr(x + 1, false);
        vector<bool>next(x + 1, false);
        curr[0]=true;
        next[0]=true;

        for (int idx = n - 1; idx >= 0; idx--) {
            for (int target = 0; target <= x; target++) {
                bool include = false;
                if (nums[idx] <= target)
                    include =next[target - nums[idx]];
                bool exclude = next[target];
                curr[target] = include || exclude;
            }
            next = curr;
        }
        return next[x];
    }
    bool canPartition(vector<int>& nums) {
        n = nums.size();
        int sum = accumulate(begin(nums), end(nums), 0);
        if (sum % 2 != 0)
            return false;
        int target = sum / 2;
        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));
        // return solveUsingRec(0, target, nums, dp);
        return solveUsingSpace(nums);
    }
};