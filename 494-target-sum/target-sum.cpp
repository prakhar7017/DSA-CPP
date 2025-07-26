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
    int solveUsingTab(vector<int>& nums, int target){
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(target+1,0));

        if(nums[0]==0) dp[0][0]=2;
        else dp[0][0]=1;

        if(nums[0]!=0 && nums[0]<=target) dp[0][nums[0]]=1;

        for(int i=1;i<n;i++){
            for(int tar=0;tar<=target;tar++){
                int exclude=dp[i-1][tar];
                int include=0;
                if(nums[i]<=tar) include=dp[i-1][tar-nums[i]];
                dp[i][tar]=include+exclude;
            }
        }
        return dp[n-1][target];
    }
    int solveUsingSpace(vector<int>& nums, int target){
        int n=nums.size();
        vector<int>prev(target+1,0);

        if(nums[0]==0) prev[0]=2;
        else prev[0]=1;

        if(nums[0]!=0 && nums[0]<=target) prev[nums[0]]=1;

        for(int i=1;i<n;i++){
            vector<int>curr(target+1,0);
            for(int tar=0;tar<=target;tar++){
                int exclude=prev[tar];
                int include=0;
                if(nums[i]<=tar) include=prev[tar-nums[i]];
                curr[tar]=include+exclude;
            }
            prev=curr;
        }
        return prev[target];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int totalSum = accumulate(begin(nums), end(nums), 0);
        if (totalSum - target < 0)
            return 0;
        if ((totalSum + target) % 2 != 0)
            return 0;
        int s2 = (totalSum - target) / 2;
        // vector<vector<int>> dp(n, vector<int>(s2 + 1, -1));
        // return solve(n - 1, nums, s2, dp);
        return solveUsingSpace(nums,s2);
    }
};