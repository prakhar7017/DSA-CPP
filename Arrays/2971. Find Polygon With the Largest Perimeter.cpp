class Solution {
public:
    typedef long long ll;
    long long largestPerimeter(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        ll ans=0;
        ll sidesSum=0;
        for(int i=0;i<n;i++){
            if(nums[i]<sidesSum){
                ans=sidesSum+nums[i];
            }
            sidesSum+=nums[i];
        }
        return ans == 0 ? -1 : ans;
    }
};

// time complexity o(nlogn) 
//space complexity is O(1)