class Solution {
public:
    int v[401];
    int solve(vector<int>&nums,int i,int n){
        //base case
        if(i>=n) return 0;
        if(v[i]!=-1){
            return v[i];
        }
        int include=nums[i]+solve(nums,i+2,n);
        int exclude=0+solve(nums,i+1,n);

        return v[i]=max(include,exclude);
    }
    int rob(vector<int>& nums) {
        int index=0;
        int n=nums.size();
        memset(v,-1,sizeof(v));
        int ans=solve(nums,index,n);
        return ans;
    }
};
// time complexity:O(2^n);
// space complexity:O(n);