class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int n=nums.size();
        long long ans=0;
        sort(begin(nums),end(nums));

        for(int i=0;i<n;i++){
            int index=lower_bound(begin(nums)+i+1,end(nums),lower-nums[i])-begin(nums);
            int x=index-i-1;

            index=upper_bound(begin(nums)+i+1,end(nums),upper-nums[i])-begin(nums);
            int y=index-i-1;
            ans+=(y-x);
        }
        return ans;
    }
};