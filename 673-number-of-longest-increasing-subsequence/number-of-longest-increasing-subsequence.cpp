class Solution {
public:
    int LIS(vector<int>& nums){
        int n = nums.size();
        vector<int>dp(n,1);
        vector<int>count(n,1);

        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i]){
                    if(dp[j]+1==dp[i]){
                        count[i]+=count[j];
                    }else if (dp[j]+1>dp[i]){
                        dp[i]=dp[j]+1;
                        count[i]=count[j];
                    }
                }
            }
        }

        int maxValue = *max_element(begin(dp),end(dp));
        int ans=0;
        for(int i=0;i<n;i++){
            if(dp[i]==maxValue){
                ans+=count[i];
            }
        }
        return ans;
    }
    int findNumberOfLIS(vector<int>& nums) {
        return LIS(nums);   
    }
};