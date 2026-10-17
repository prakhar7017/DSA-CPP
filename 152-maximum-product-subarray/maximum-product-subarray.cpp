class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int ans=nums[0];
        for(int i=0;i<n;i++){
            int product = nums[i];
            ans = max(ans,product);
            for(int j=i+1;j<n;j++){
                product = product*nums[j];
                ans = max(ans,product);
            }
        }
        return ans;
    }
};