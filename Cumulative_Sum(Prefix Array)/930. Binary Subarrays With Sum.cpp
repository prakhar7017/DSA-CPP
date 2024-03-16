class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n=nums.size();
        int cumSum=0;
        unordered_map<int,int>mp;
        mp[0]=1;
        int ans=0;
        for(int i=0;i<n;i++){
            cumSum+=nums[i];
            if(mp.find(cumSum-goal)!=mp.end()){
                ans+=mp[cumSum-goal];
            }
            mp[cumSum]++;
        }
        return ans;
    }
};