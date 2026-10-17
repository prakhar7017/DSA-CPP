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
    bool bottomUp(int idx,string&s,unordered_set<string>&st){
        int n = s.length();
        vector<bool>dp(n+1,false);

        dp[n]=true;
        for(int idx = n-1;idx>=0;idx--){
            for(int l=1;l<=n-idx;l++){
                string temp = s.substr(idx,l);
                if(st.count(temp) && dp[idx+l]) {
                    dp[idx]=true;
                    break;
                }
            }
        }
        return dp[0];
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        n=s.length();
        unordered_set<string>st;
        vector<int>dp(n+1,-1);
        for(string &word:wordDict){
            st.insert(word);
        }
        return bottomUp(0,s,st);
    }
};