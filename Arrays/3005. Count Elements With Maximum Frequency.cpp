class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int>mp;
        int freq=0;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
            freq=max(freq,mp[nums[i]]);
        }
        int ans=0;
        for(auto it:mp){
            if(it.second==freq){
                ans+=freq;
            }
        }
        return ans;
    }
};

// time complexity: O(n)
// space complexity: O(n)