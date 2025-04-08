class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        vector<bool>mp(128);
        int n=nums.size();
        for(int i=n-1;i>=0;i--){
            if(mp[nums[i]]){
                return i/3 +1;
            }
            mp[nums[i]]=true;
        }
        return 0;
    }
};