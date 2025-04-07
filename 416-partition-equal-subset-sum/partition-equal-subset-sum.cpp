class Solution {
public:
    bool solveUsingRec(vector<int>& nums,int index,int targetSum,vector<vector<int>>&dp)    {
        if(index>=nums.size() || targetSum<0 ) return false;
        // if(index==nums.size() && targetSum==0) return true;
        if(targetSum==0) return true;
        if(dp[index][targetSum]!=-1) return dp[index][targetSum];
        bool include=solveUsingRec(nums,index+1,targetSum-nums[index],dp);
        bool exclude=solveUsingRec(nums,index+1,targetSum,dp);
        return dp[index][targetSum]=include || exclude;

    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=accumulate(begin(nums),end(nums),0);
        if(sum & 1) return false;

        int targetSum=sum>>1;
        vector<vector<int>>dp(n+1,vector<int>(targetSum+1,-1));
        return solveUsingRec(nums,0,targetSum,dp);

    }
};