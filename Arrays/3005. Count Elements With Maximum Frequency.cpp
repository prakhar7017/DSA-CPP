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

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int arr[101]={0};
        int freq=0;
        for(int i=0;i<nums.size();i++){
            arr[nums[i]]++;
            freq=max(freq,arr[nums[i]]);
        }
        return count(arr,arr+101,freq)*freq;
    }
};


// one pass
class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int maxFreq=0;
        int ans=0;
        vector<int>v(101);
        for(int i=0;i<nums.size();i++){
            v[nums[i]]++;
            int freq= v[nums[i]];
            if(freq>maxFreq){
                maxFreq=freq;
                ans=freq;
            }else if(freq==maxFreq){
                ans+=maxFreq;
            }
        }
        return ans;
    }
};