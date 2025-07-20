class Solution {
public:
    bool solve(int index, int target, vector<int>& nums) {
        // basecase
        if (target == 0)
            return 1;
        if (index >= nums.size())
            return 0;

        int exclude = solve(index + 1, target, nums);
        int include = 0;
        if (nums[index] <= target)
            include = solve(index + 1, target - nums[index], nums);
        return include || exclude;
    }

    bool solveUsingTab(int target,vector<int>& nums){
        int n=nums.size();
        vector<vector<bool>>dp(n,vector<bool>(target+1,false));
        for(int i=0;i<n;i++) dp[i][0]=true;
        if(nums[0]<=target) dp[0][nums[0]]=true;
        for(int i=1;i<n;i++){
            for(int tar=1;tar<=target;tar++){
                bool exclude=dp[i-1][tar];
                bool include=false;
                if(nums[i]<=tar) include=dp[i-1][tar-nums[i]];
                dp[i][tar]=(include || exclude);
            }
        }
        return dp[n-1][target];
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(begin(nums), end(nums),0);
        if (sum & 1)
            return false;
        int targetSum = sum >> 1;
        // return solve(0, targetSum, nums);
        return solveUsingTab(targetSum,nums);
    }
};