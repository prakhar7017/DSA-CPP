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

// time complexity : O(nlogn) n is the size of the array


// Morre Voting Algorithm : https://www.youtube.com/watch?v=nP_ns3uSh80


class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        int count=0;
        int el;
        for(int i=0;i<n;i++){
            if(count==0){
                count++;
                el=nums[i];
            }else if(nums[i]==el){
                count++;
            }else{
                count--;
            }
        }
        return el;
    }
};

// time complexity : O(n) n is the size of the array

