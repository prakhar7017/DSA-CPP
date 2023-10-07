class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>>mp;
        for(auto str:strs){
            string s=str;
            sort(s.begin(),s.end());
            mp[s].push_back(str);
        }
        vector<vector<string>>ans;
        for(auto it=mp.begin();it!=mp.end();it++){
            ans.push_back(it->second);
        }
        return ans;
    }
};

// time complexity:O(n*mlogm) n is the length of strs, m is the length of the longest string in strs 

// -----------------------------------------------------------------------------------------
class Solution {
    private:
    std::array<int,256> hash(string str){
        std::array<int,256>hash={0};
        for(int i=0;i<str.size();i++){
            hash[str[i]]++;
        }
        return hash;
    }
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<std::array<int,256>,vector<string>>mp;
        for(auto str:strs){
            mp[hash(str)].push_back(str);
        }
        vector<vector<string>>ans;
        for(auto it=mp.begin();it!=mp.end();it++){
            ans.push_back(it->second);
        }
        return ans;
    }
};

// time complexity:O(n*m) n is the length of strs, m is the length of the longest string in strs