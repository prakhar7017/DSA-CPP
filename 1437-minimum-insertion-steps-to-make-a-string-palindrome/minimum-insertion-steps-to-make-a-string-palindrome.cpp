class Solution {
public:
    int solveUsingRec(int start,int end,string &s,vector<vector<int>>&dp){
        // basecase
        if(start>=end) return 0;
        if(dp[start][end]!=-1) return dp[start][end];
        if(s[start]==s[end]) return dp[start][end]=solveUsingRec(start+1,end-1,s,dp);
        else return dp[start][end]=1+min(solveUsingRec(start+1,end,s,dp),solveUsingRec(start,end-1,s,dp));
    }
    int minInsertions(string s) {
        vector<vector<int>>dp(s.length(),vector<int>(s.length(),-1));
        return solveUsingRec(0,s.length()-1,s,dp);
    }
};