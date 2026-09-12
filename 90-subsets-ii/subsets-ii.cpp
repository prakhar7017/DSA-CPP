class Solution {
public:
    vector<vector<int>> ans;
    void solve(int idx,vector<int>& v, vector<int>& nums) {
        ans.push_back(v);  
        for(int i=idx;i<nums.size();i++){
            if( i>idx && nums[i]==nums[i-1]) continue;
            v.push_back(nums[i]);
            solve(i+1,v,nums);
            v.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> v;
        sort(begin(nums),end(nums));
        solve(0, v, nums);
        return ans;
    }
};