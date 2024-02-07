class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>mp;
        int n=s.length();
        if(n==0){
            return "";
        }
        for(int i=0;i<n;i++){
            char ch=s[i];
            mp[ch]++;
        }
        priority_queue<pair<int,char>>maxi;
        for(auto it:mp){
            maxi.push({it.second,it.first});
        }
        string ans="";
        while(!maxi.empty()){
            auto top=maxi.top();
            maxi.pop();
            for(int i=0;i<top.first;i++){
                ans.push_back(top.second);
            }
        }
        return ans;
    }
};