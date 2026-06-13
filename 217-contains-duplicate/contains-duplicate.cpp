class Solution {
public:
    bool containsDuplicateOptimised(vector<int>&arr){
        int n = arr.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            if(mp.find(arr[i])!=mp.end()) return true;
            mp[arr[i]]++;
        }
        return false;
    }
    bool containsDuplicate(vector<int>& nums) {
        bool ans = containsDuplicateOptimised(nums);
        return ans;
    }
};