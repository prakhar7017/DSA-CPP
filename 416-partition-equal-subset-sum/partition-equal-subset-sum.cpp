class Solution {
public:
    bool solveUsingRec(vector<int>& nums,int targetSum,int index,vector<vector<int>>&dp){
        if(index>=nums.size() || targetSum<0){
            return false;
        }
        if(targetSum==0){
            return true;
        }
        if(dp[index][targetSum]!=-1){
            return dp[index][targetSum];
        }

        bool include=solveUsingRec(nums,targetSum-nums[index],index+1,dp);
        bool exclude=solveUsingRec(nums,targetSum,index+1,dp);

        return dp[index][targetSum]=include || exclude ;
    }
    bool solveUsingTab(vector<int>& nums,int targetSum){
        int n=nums.size();
        vector<vector<int>>dp(n+2,vector<int>(targetSum+2,0));

        for(int row=0;row<n;row++){
            dp[row][targetSum]=0;
        }


        for(int index=n-1;index>=0;index--){
            for(int target=targetSum;target>=0;target--){
                bool include=dp[target-nums[index]][index+1];
                bool exclude=dp[target][index+1];

                dp[target][index]=include || exclude ;
            }
        }

        return dp[targetSum][0];
    }
    bool solve(int index,int targetSum,vector<int>& nums,vector<vector<int>>&dp){
        if(index>=nums.size()) return false;
        if(targetSum<0) return false;
        if(targetSum==0) return true;
        if(dp[index][targetSum]!=-1){
            return dp[index][targetSum];
        }

        int exclude=solve(index+1,targetSum,nums,dp);
        int include=solve(index+1,targetSum-nums[index],nums,dp);
        return dp[index][targetSum]=include || exclude;
    }
    bool canPartition(vector<int>& nums) {
        // int index=0;
        // int totalSum=accumulate(nums.begin(),nums.end(),0);

        // if(totalSum & 1){
        //     // odd sum cannot be partioned
        //     return false;
        // }
        // int targetSum=totalSum>>1;
        // // vector<vector<int>>dp(nums.size()+1,vector<int>(targetSum+1,-1));
        // return solveUsingTab(nums,targetSum);

        int totalSum=accumulate(nums.begin(),nums.end(),0);
        int index=0;
        if(totalSum & 1){
            return false;
        }
        int targetSum=totalSum>>1;
        vector<vector<int>>dp(nums.size()+1,vector<int>(targetSum+1,-1));
        return solve(index,targetSum,nums,dp);

    }
};