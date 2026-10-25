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
    int maxProduct(vector<int>& nums) {
        return bruteForce(nums);   
    }
};