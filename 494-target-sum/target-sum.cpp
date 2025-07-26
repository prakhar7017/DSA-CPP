class Solution {
public:
    int solve(int index, vector<int>& nums, int target,
              vector<vector<int>>& dp) {
        // basecase
        if (index == 0) {
            if (target == 0 && nums[index] == 0)
                return 2;
            if (target == 0 || nums[index] == target)
                return 1;
            return 0;
        }
        if(dp[index][target]!=-1) return dp[index][target];
        int exclude = solve(index - 1, nums, target,dp);
        int include = 0;
        if (nums[index] <= target)
            include = solve(index - 1, nums, target - nums[index],dp);

        return dp[index][target]=(exclude + include);
    }
    // int solveUsingTab(vector<int>& nums, int target){
    //     int n=nums.size();
    //     vector<int>
    // }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int totalSum = accumulate(begin(nums), end(nums), 0);
        if (totalSum - target < 0)
            return 0;
        if ((totalSum + target) % 2 != 0)
            return 0;
        int s2 = (totalSum - target) / 2;
        vector<vector<int>> dp(n, vector<int>(s2 + 1, -1));
        return solve(n - 1, nums, s2, dp);
    }
};