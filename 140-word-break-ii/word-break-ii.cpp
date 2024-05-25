class Solution {
public:
    vector<string> solve(string &s,unordered_map<string,bool>&dict,int index){
        // base case
        if(index==s.length()) return {""};

        vector<string>ans;
        string word="";

        for(int i=index;i<s.length();++i){
            word.push_back(s[i]);
            if(dict.find(word)==dict.end()) continue; // not found

            vector<string>right=solve(s,dict,i+1);
            for(string eachRight:right){
                string endPart;
                if(eachRight.length()>0){
                    endPart=" "+eachRight;
                }
                ans.push_back(word+endPart);
            }
        }
        return ans;
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string,bool>dict;
        for(auto word:wordDict){
            dict[word]=1;
        }
        return solve(s,dict,0);
    }
};