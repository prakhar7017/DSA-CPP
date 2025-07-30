class Solution {
public:
    int solveUsingRec(int idx1, int idx2, string& text1, string& text2,
                      vector<vector<int>>& dp) {
        // basecase
        if (idx1 < 0 || idx2 < 0)
            return 0;

        if (dp[idx1][idx2] != -1)
            return dp[idx1][idx2];
        if (text1[idx1] == text2[idx2])
            return dp[idx1][idx2] =
                       1 + solveUsingRec(idx1 - 1, idx2 - 1, text1, text2, dp);

        return dp[idx1][idx2] =
                   max(solveUsingRec(idx1 - 1, idx2, text1, text2, dp),
                       solveUsingRec(idx1, idx2 - 1, text1, text2, dp));
    }
    int solveUsingTab(string& t1, string& t2) {
        int n = t1.length();
        int m = t2.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        // basecase
        for (int i = 0; i <= n; i++)
            dp[i][0] = 0;
        for (int j = 0; j <= m; j++)
            dp[0][j] = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (t1[i-1] == t2[j-1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        return dp[n][m];
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();
        // vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        // return solveUsingRec(n - 1, m - 1, text1, text2, dp);
        return solveUsingTab(text1, text2);
    }
};