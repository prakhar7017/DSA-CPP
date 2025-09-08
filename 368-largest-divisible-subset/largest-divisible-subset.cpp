class Solution {
public:
    void solveUsingRec(int idx, int prev, vector<int>& nums, vector<int>& temp,
                       vector<int>& result) {
        if (idx >= nums.size()) {
            if (temp.size() > result.size()) {
                result = temp;
            }
            return;
        }
        if (prev == -1 || nums[idx] % prev == 0) {
            temp.push_back(nums[idx]);
            solveUsingRec(idx + 1, nums[idx], nums, temp, result);
            temp.pop_back(); // backtrack
        }
        solveUsingRec(idx + 1, prev, nums, temp, result);
    }

    vector<int> solveUsingBottomUp(vector<int>& nums) { 
        int n = nums.size(); 
        vector<int>dp(n,1);
        vector<int>parent(n,-1);
        int lastChosenIndex=0;
        int maxLen=1;

        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0){
                    if(dp[i]<dp[j]+1){
                        dp[i]=dp[j]+1;
                        parent[i]=j;
                    }

                    if(dp[i]>maxLen){
                        maxLen=dp[i];
                        lastChosenIndex=i;
                    }
                }
            }
        }

        vector<int>ans;
        while(lastChosenIndex>=0){
            ans.push_back(nums[lastChosenIndex]);
            lastChosenIndex=parent[lastChosenIndex];
        }
        return ans;

    }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(begin(nums), end(nums));
        vector<int> result;
        vector<int> temp;
        int prev = -1;

        // solveUsingRec(0, prev, nums, temp, result);
        return solveUsingBottomUp(nums);
    }
};