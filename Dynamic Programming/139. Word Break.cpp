class Solution {
public:
    bool check(vector<string>& wordDict,string &word){
        for(auto dictWord:wordDict){
            if(dictWord==word){
                return true;
            }
        }
        return false;
    }
    bool solve(string &s, vector<string>& wordDict,int start,vector<bool>&dp){
        // base case
        if(start==s.size()) return true;

        if(dp[start]!=true){
            return dp[start];
        }
        // one case, make a string
        string word="";
        bool flag=false;
        for(int i=start;i<s.size();i++){
            word+=s[i];
            if(check(wordDict,word)){
                flag= flag || solve(s,wordDict,i+1,dp);
            }
        }
        return dp[start]=flag;
    }
    bool solveUsingTab(string &s,vector<string>&wordDict){
        vector<bool>dp(s.length()+1,true);

        for(int start=s.length()-1;start>=0;start--){
            string word="";
            bool flag=false;
            for(int i=start;i<s.size();i++){
                word+=s[i];
                if(check(wordDict,word)){
                    flag= flag || dp[i+1];
                }
            }
            dp[start]=flag;
        }
        return dp[0];
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        // vector<bool>dp(s.length()+1,true);
        return solveUsingTab(s,wordDict);
    }
};