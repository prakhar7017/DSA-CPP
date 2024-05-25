class Solution {
public:
    vector<string> solve(string &s, vector<string>& wordDict,int start,unordered_map<string,bool>&dict){
        if(start>=s.size()){
            return {""};
        }
        vector<string>ans;
        string word;

        for(int i=start;i<s.length();i++){
            word.push_back(s[i]);
            if(dict.find(word)==dict.end()) { // not a valid part 
                continue;
            }

            // found a valid word
            auto right=solve(s,wordDict,i+1,dict);
            for(auto eachRight:right){
                string endPart;
                if(eachRight.length()>0){
                    endPart=" "+ eachRight;
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
        return solve(s,wordDict,0,dict);
    }
};