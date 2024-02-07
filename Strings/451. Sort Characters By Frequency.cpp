class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>mp;
        int n=s.length();
        for(int i=0;i<n;i++){
            char ch=s[i];
            mp[ch]++;
        }
        vector<pair<char,int>>v;
        for(auto it:mp){
            v.push_back({it.first,it.second});
        }
        auto lambda=[&](pair<char,int>&a,pair<char,int>&b){
            return a.second>b.second;
        };
        sort(v.begin(),v.end(),lambda);
        string ans="";
        for(int i=0;i<v.size();i++){
            if(v[i].second>0){
                char ch=v[i].first;
                int freq=v[i].second;
                string temp=string(freq,ch);
                ans+=temp;
            }
        }
        return ans;
    }
};

// 2nd approach without using map
class Solution {
public:
    typedef pair<char,int>T;
    string frequencySort(string s) {
        int n=s.length();
        vector<T>v(123);
        for(char &ch:s){
            int freq=v[ch].second;
            v[ch]={ch,freq+1};
        }
        auto lambda=[&](T &a,T &b){
            return a.second>b.second;
        };
        sort(v.begin(),v.end(),lambda);
        string ans="";
        for(int i=0;i<v.size();i++){
            if(v[i].second>0){
                char ch=v[i].first;
                int freq=v[i].second;
                string temp=string(freq,ch);
                ans+=temp;
            }
        }
        return ans;
    }
};
// using vector<pair<char,int>> instead of unordered_map<char,int> to store frequency of each character. and then sort the vector of pairs based on frequency of characters.