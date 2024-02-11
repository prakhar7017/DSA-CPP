class Solution
{
public:
    int v[401];
    int solve(vector<int> &nums, int i, int n)
    {
        // base case
        if (i >= n)
            return 0;
        if (v[i] != -1)
        {
            return v[i];
        }
        int include = nums[i] + solve(nums, i + 2, n);
        int exclude = 0 + solve(nums, i + 1, n);

        return v[i] = max(include, exclude);
    }
    int rob(vector<int> &nums)
    {
        int index = 0;
        int n = nums.size();
        memset(v, -1, sizeof(v));
        int ans = solve(nums, index, n);
        return ans;
    }
};
// time complexity:O(2^n);
// space complexity:O(n);

// Bottom up approach
int solveTabulation(vector<int> &nums)
{
    // step 1
    int n = nums.size();
    vector<int> dp(n + 1, 0);
    // step2 analyse inital state
    dp[n - 1] = nums[n - 1];

    for (int index = n - 2; index >= 0; index--)
    {
        // include
        int include = nums[index] + dp[index + 2];
        // exclude
        int exclude = 0 + dp[index + 1];

        dp[index] = max(include, exclude);
    }
    return dp[0];
}

// space optimized approach
int solveSpaceOpt(vector<int> &nums)
{
    // step 1
    int n = nums.size();
    // vector<int>dp(n+1,0);
    // step2 analyse inital state
    // dp[n-1]=nums[n-1];
    int prev = nums[n - 1];
    int next = 0;
    int curr;

    for (int index = n - 2; index >= 0; index--)
    {
        // include
        int include = nums[index] + next;
        // exclude
        int exclude = 0 + prev;

        curr = max(include, exclude);
        // updation
        next = prev;
        prev = curr;
    }
    return prev;
}
