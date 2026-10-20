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
    int solveUsingBottomUp(string&t1, string&t2){
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(t1[i]==t2[j]){
                    dp[i][j]= 1 + dp[i+1][j+1];
                }else{
                    dp[i][j]=max(dp[i+1][j],dp[i][j+1]);
                }
            }
        }
        return dp[0][0];
    }
    int solveUsingSpaceOptmization(string&t1, string&t2){
        vector<int>curr(n+1,0);
        vector<int>next(n+1,0);
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(t1[i]==t2[j]){
                    curr[j]= 1 + next[j+1];
                }else{
                    curr[j]=max(next[j],curr[j+1]);
                }
            }
            next = curr;
        }
        return next[0];
    }
    int longestCommonSubsequence(string text1, string text2) {
        m = text1.length();
        n = text2.length();
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        // return solveUsingMemo(0,0,text1,text2,dp);
        return solveUsingSpaceOptmization(text1,text2);
    }
};