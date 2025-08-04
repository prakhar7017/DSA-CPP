class Solution {
public:
    int solveUsingRec(int i,int j,string &s1,string &s2){
        // basecase
        if(i<0 || j<0) return 0;
        if(s1[i]==s2[j]) return 1+solveUsingRec(i-1,j-1,s1,s2);
        else return max(solveUsingRec(i,j-1,s1,s2),solveUsingRec(i-1,j,s1,s2));
    }
    int solveUsingTab(string &s1,string &s2){
        int n=s1.length();
        int m=s2.length();

        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1]) dp[i][j]=1+dp[i-1][j-1];
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[n][m];
    }
    int longestPalindromeSubseq(string s) {
        string temp = s;
        reverse(temp.begin(),temp.end());
        int n=s.length();
        int m=temp.length();
        // return solveUsingRec(n-1,m-1,s,temp);
        return solveUsingTab(s,temp);
        
    }
};