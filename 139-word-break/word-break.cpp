class Solution {
public:
    int n;
    bool solve(int idx,string&s,unordered_set<string>&st,vector<int>&dp){
        if(idx>=n) return true;

        if(dp[idx]!=-1) return dp[idx];

        if(st.count(s)) return dp[idx]=true;

        for(int l=1;l<=n-idx;l++){
            string temp = s.substr(idx,l);
            if(st.count(temp) && solve(idx+l,s,st,dp)) return dp[idx]=true;
        }
        return dp[idx]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        n=s.length();
        unordered_set<string>st;
        vector<int>dp(n+1,-1);
        for(string &word:wordDict){
            st.insert(word);
        }
        return solve(0,s,st,dp);
    }
};