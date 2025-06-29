class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            int newtarget=target-nums[i];
            if(mp.find(newtarget)!=mp.end()){
                return {i,mp[newtarget]};
            }
            mp[nums[i]]=i;
        }

        return {};
    }
};