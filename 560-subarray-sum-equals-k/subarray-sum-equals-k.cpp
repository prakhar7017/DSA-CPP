class Solution {
public:
    int solveUsingOptimal(vector<int>& nums, int k){
        int n = nums.size();
        unordered_map<int,int>mp; //{cs,count};
        int cs = 0;
        mp.insert({cs,1});
        int ans=0;
        for(int i=0;i<n;i++){
            cs+=nums[i];
            if(mp.find(cs-k)!=mp.end()){
                ans+=mp[cs-k];
            }
            mp[cs]++;
        }
        return ans;
    }
    int subarraySum(vector<int>& nums, int k) {
        return solveUsingOptimal(nums,k);
    }
};