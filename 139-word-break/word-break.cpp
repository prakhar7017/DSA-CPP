class Solution {
public:
    bool solve(string &s,unordered_map<string,bool>&dict,int index){
        // base case
        if(index==s.length()) return true;

        string word="";
        bool flag=false;
        for(int i=index;i<s.length();++i){
            word.push_back(s[i]);
            if(dict.find(word)!=dict.end()){
                flag= flag || solve(s,dict,i+1);
            }
        }
        return flag;
    }
    bool solveusingRec(string &s,unordered_map<string,bool>&dict,int index,vector<int>&dp){
        // base case
        if(index==s.length()) return true;

        if(dp[index]!=-1){
            return dp[index];
        }

        string word="";
        bool flag=false;
        for(int i=index;i<s.length();++i){
            word.push_back(s[i]);
            if(dict.find(word)!=dict.end()){
                flag= flag || solveusingRec(s,dict,i+1,dp);
            }
        }
        return dp[index]=flag;
    }
    bool solveusingBU(string &s,unordered_map<string,bool>&dict){
        vector<bool>dp(s.length()+1,true);
        for(int index=s.length()-1;index>=0;--index){
            string word="";
            bool flag=false;
            for(int i=index;i<s.length();++i){
                word.push_back(s[i]);
                if(dict.find(word)!=dict.end()){
                    flag= flag || dp[i+1];
                }
            }
            dp[index]=flag;
        }
        return dp[0];
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string,bool>dict;
        for(string word:wordDict){
            dict[word]=1;
        }
        // vector<int>dp(s.length()+1,-1);
        // return solveusingRec(s,dict,0,dp);
        return solveusingBU(s,dict);
    }
};