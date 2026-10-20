class Solution {
public:
    int m,n;
    int solveUsingMemo(int i,int j,string&t1, string&t2,vector<vector<int>>&dp){
        if(i>=m || j>=n) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(t1[i]==t2[j]){
            return dp[i][j]=1 + solveUsingMemo(i+1,j+1,t1,t2,dp);
        }
        return dp[i][j]=max(solveUsingMemo(i+1,j,t1,t2,dp),solveUsingMemo(i,j+1,t1,t2,dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
        m = text1.length();
        n = text2.length();
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return solveUsingMemo(0,0,text1,text2,dp);
    }
};