class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mp;
        int n = nums.size();
        for(int i=0;i<n;i++){
            int currNum = nums[i];
            int diffHaveSeen = target-currNum;
            if(mp.find(diffHaveSeen)!=mp.end()){
                return {i,mp[diffHaveSeen]};
            }
            mp[nums[i]]=i;
        }
        return {};
    }
};