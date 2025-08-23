class Solution {
public:
    bool solveUsingRec(int n,int m,string &s, string &p,vector<vector<int>>&dp){
        // basecase
        if(n==0 && m==0) return true;
        if(n>0 && m==0) return false;
        if(n==0 && m>0){
            for(int i=0;i<m;i++){
                if(p[i]!='*') return false;
            }
            return true;
        }
        if(dp[n][m]!=-1) return false;
        if(s[n-1]==p[m-1] || p[m-1]=='?'){
            return dp[n][m]=solveUsingRec(n-1,m-1,s,p,dp);
        }else if(p[m-1]=='*'){
            return dp[n][m]=solveUsingRec(n,m-1,s,p,dp) || solveUsingRec(n-1,m,s,p,dp); 
        }
        return dp[n][m]=false;
    }
    bool isMatch(string s, string p) {
        int n=s.length();
        int m=p.length();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return solveUsingRec(n,m,s,p,dp);   
    }
};