class Solution {
public:
    int bruteForce(vector<int>& nums){
        int n = nums.size();
        int ans=nums[0];
        for(int i=0;i<n;i++){
            int product = 1;
            for(int j=i;j<n;j++){
                product = product*nums[j];
                ans = max(ans,product);
            }
        }
        return ans;
    }
    int optimised(vector<int>& nums){
        int n = nums.size();
        int prefix = 1;
        int suffix = 1;
        int ans = INT_MIN;
        for(int i=0;i<n;i++){
            if(prefix == 0) prefix = 1;
            if(suffix == 0) suffix = 1;

            prefix = prefix * nums[i];
            suffix = suffix * nums[n-i-1];

            ans = max(ans,max(prefix,suffix));
        }
        return ans;
    }
    int maxProduct(vector<int>& nums) {
        return optimised(nums);   
    }
};