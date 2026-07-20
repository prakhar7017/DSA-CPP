class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            int a = nums[i];
            int b = target - a;
            if(mp.find(b)!=mp.end()){
                return {i,mp[b]};
            }
            mp[a]=i;
        }
        return {};
    }
};