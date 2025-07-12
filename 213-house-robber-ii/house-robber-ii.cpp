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
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        if (n == 2)
            return max(nums[0], nums[1]);

        // Case 1: Rob from house 0 to n-2
        vector<int> dp1(n, -1);
        int take0thHouse = solve(0, n - 2, nums, dp1);

        // Case 2: Rob from house 1 to n-1
        vector<int> dp2(n, -1);
        int take1stHouse = solve(1, n - 1, nums, dp2);

        return max(take0thHouse, take1stHouse);
    }
};