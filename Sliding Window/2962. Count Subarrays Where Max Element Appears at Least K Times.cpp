class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        int maxElement=*max_element(begin(nums),end(nums));
        int i=0;
        int j=0;
        long long ans=0;
        int countMax=0;
        while(j<n){
            if(nums[j]==maxElement){
                ++countMax;
            }
            while(i<=j && countMax>=k){
                ans+=n-j;
                if(nums[i]==maxElement){
                    --countMax;
                }
                ++i;
            }
            ++j;
        }
        return ans;
    }
}; 

// time complexity : o(n)
// space complexity : o(1)