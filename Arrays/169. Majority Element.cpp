class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        map<int,int>mp;
        for(auto num:nums){
            mp[num]++;
        }

        for(auto it:mp){
            if(it.second>(n>>1)){
                return it.first;
            }
        }
        return -1;
    }
};

time complexity : O(nlogn) n is the size of the array