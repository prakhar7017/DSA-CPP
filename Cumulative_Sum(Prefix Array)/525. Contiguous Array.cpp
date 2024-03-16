class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int len=0;
        int n=nums.size();
        unordered_map<int,int>mp;
        mp[0]=-1;
        int cumSum=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                int temp=-1;  // if 0 is encountered then we will consider it as -1, because 1-1=0 and we will find 0 as target.
                cumSum+=temp;
                if(mp.find(cumSum-0)!=mp.end()){
                    len=max(len,i-mp[cumSum-0]);
                }else{
                    mp[cumSum]=i;
                }
            }
            else{
                cumSum+=nums[i];
                if(mp.find(cumSum-0)!=mp.end()){
                    len=max(len,i-mp[cumSum-0]);
                }else{
                    mp[cumSum]=i;
                }
            }
        }
        return len;
    }
};

// time complexity is O(n)
// space complexity is O(n)