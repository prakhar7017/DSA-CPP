class Solution {
public:
    int n;
    int solveUsingMemo(int curr, int prev, vector<int>& nums,
                       vector<vector<int>>& dp) {
        if (curr >= n)
            return 0;
        if (dp[curr][prev + 1] != -1)
            return dp[curr][prev + 1];
        int include = 0;
        if (prev == -1 || nums[curr] > nums[prev]) {
            include = 1 + solveUsingMemo(curr + 1, curr, nums, dp);
        }
        int exclude = 0 + solveUsingMemo(curr + 1, prev, nums, dp);
        return dp[curr][prev + 1] = max(include, exclude);
    }
    int bottomUp(vector<int>& nums) {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int curr = n - 1; curr >= 0; curr--) {
            for (int prev = n - 1; prev >= -1; prev--) {
                int include = 0;
                if (prev == -1 || nums[curr] > nums[prev]) {
                    include = 1 + dp[curr + 1][curr + 1];
                }
                int exclude = 0 + dp[curr + 1][prev + 1];
                dp[curr][prev + 1] = max(include, exclude);
            }
        }
        return dp[0][0];
    }
    int spaceOptimised(vector<int>& nums) {
        vector<int>currRow(n + 1, 0);
        vector<int>nextRow(n + 1, 0);

        for (int curr = n - 1; curr >= 0; curr--) {
            for (int prev = n - 1; prev >= -1; prev--) {
                int include = 0;
                if (prev == -1 || nums[curr] > nums[prev]) {
                    include = 1 + nextRow[curr + 1];
                }
                int exclude = 0 + nextRow[prev + 1];
                currRow[prev + 1] = max(include, exclude);
            }
            nextRow = currRow;
        }
        return currRow[0];
    }
    int BIS(vector<int>& nums){
        vector<int>ans;
        for(int i=0;i<n;i++){
            auto it= lower_bound(begin(ans),end(ans),nums[i]);

            if(it == end(ans)){
                ans.push_back(nums[i]);
            }else{
                *it = nums[i];
            }
        }
        return ans.size();
    }
    int lengthOfLIS(vector<int>& nums) {
        n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        // return solveUsingMemo(0, -1, nums, dp);
        return BIS(nums);
    }
};