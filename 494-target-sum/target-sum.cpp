class Solution {
public:
    int n;
    int solveUsingMemo(int idx,int sum,int target,vector<int>& nums){
        if(idx == n){
            if(sum == target) return 1;
            return 0;
        }
        int pos = solveUsingMemo(idx+1,sum+nums[idx],target,nums);
        int neg = solveUsingMemo(idx+1,sum-nums[idx],target,nums);
        return pos+neg;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        n = nums.size();
        return solveUsingMemo(0,0,target,nums);
    }
};