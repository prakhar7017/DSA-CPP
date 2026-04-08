class Solution {
public:
    int mod = 1000000007;
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();

        for(vector<int>query:queries){
            int l = query[0];
            int r = query[1];
            int k = query[2];
            int v = query[3];

            for(int i=l;i<=r;i+=k){
                nums[i]=(1LL * nums[i]*v)%(mod);
            }
        }

        int ans = 0;
        for(int num:nums){
            ans^=num;
        } 
        return ans;
    }
};