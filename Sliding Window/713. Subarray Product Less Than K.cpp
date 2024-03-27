class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n=nums.size();
        if(k<=1){
            return 0;
        }
        int count=0;
        int i=0;
        int j=0;
        int prod=1;
        while(j<n){
            prod*=nums[j];
            while(prod>=k){
                prod/=nums[i];
                ++i;
            }
            count+=(j-i+1); // number of subarray ending at j
            ++j;
        }
        return count;
    }
};

// time complexity : O(n)
// space complexity : O(1)
