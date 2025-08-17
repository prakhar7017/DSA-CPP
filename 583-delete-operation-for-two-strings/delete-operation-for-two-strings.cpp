class Solution {
public:
    int LCS(int i, int j, string& s1, string& s2, vector<vector<int>> dp) {
        if (i < 0 || j < 0)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        if (s1[i] == s2[j])
            return dp[i][j] = 1 + LCS(i - 1, j - 1, s1, s2, dp);
        return dp[i][j] = max(LCS(i, j - 1, s1, s2,dp), LCS(i - 1, j, s1, s2, dp));
    }
    int bottomUpLCS(string &w1, string &w2){
        int n=w1.size();
        int m=w2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(w1[i-1]==w2[j-1]) dp[i][j]=1+dp[i-1][j-1];
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }

        return dp[n][m];
    }
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size(), vector<int>(word2.size(), -1));
        // int longestCommonSub =
        //     LCS(word1.size() - 1, word2.size() - 1, word1, word2, dp);
        int longestCommonSub =
            bottomUpLCS(word1, word2);

        return word1.size()+word2.size()-2*longestCommonSub;
    }
};