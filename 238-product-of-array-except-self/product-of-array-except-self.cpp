class Solution {
public:
    vector<int> bruteForce(vector<int>& nums){
        int n =nums.size();
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            int prod=1;
            for(int j=0;j<n;j++){
                if(i==j) continue;
                prod*=nums[j];
            }
            ans[i]=prod;
        }
        return ans;
    }
    vector<int> twoPassApproach(vector<int>& nums){
        int n =nums.size();
        vector<int>prefix(n);
        vector<int>suffix(n);
        for(int i=0;i<n;i++){
            int prod=1;
            if(i==0) prefix[i]=prod;
            else{
                prefix[i]=prefix[i-1]*nums[i-1];
            }
        }
        for(int i=n-1;i>=0;i--){
            int prod=1;
            if(i==n-1) suffix[i]=prod;
            else{
                suffix[i]=suffix[i+1]*nums[i+1];
            }
        }
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            ans[i]=prefix[i]*suffix[i];
        }
        return ans;
    }
    vector<int> optimised(vector<int>& nums){
        int n =nums.size();
        vector<int>prefix(n);
        prefix[0]=1;
        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]*nums[i-1];
        }
        int right=1;
        for(int i=n-1;i>=0;i--){
            prefix[i]*=right;
            right*=nums[i];
        }
        return prefix;
    }
    vector<int> productExceptSelf(vector<int>& nums) {
        return optimised(nums);
    }
};