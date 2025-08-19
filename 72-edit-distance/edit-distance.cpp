class Solution {
public:
    int solveUsingRec(int n, int m, string& w1, string& w2,
                      vector<vector<int>>& dp) {
        // basecase
        if (n == 0)
            return m; // insert m
        if (m == 0)
            return n; // delete n
        if (dp[n][m] != -1)
            return dp[n][m];
        if (w1[n - 1] == w2[m - 1]) {
            return dp[n][m] = solveUsingRec(n - 1, m - 1, w1, w2, dp);
        } else {
            // 3 options
            int insertC = 1 + solveUsingRec(n, m - 1, w1, w2, dp);
            int deleteC = 1 + solveUsingRec(n - 1, m, w1, w2, dp);
            int replaceC = 1 + solveUsingRec(n - 1, m - 1, w1, w2, dp);
            return dp[n][m] = min({insertC, deleteC, replaceC});
        }
        return -1;
    }
    int solveUsingTab(string& w1, string& w2) {
        int n = w1.length();
        int m = w2.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1));

        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                if (i == 0 || j == 0)
                    dp[i][j] = i + j;
                else if (w1[i - 1] == w2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    // 3 options
                    int insertC = 1 + dp[i][j - 1];
                    int deleteC = 1 + dp[i - 1][j];
                    int replaceC = 1 + dp[i - 1][j-1];
                    dp[i][j] = min({insertC, deleteC, replaceC});
                }
            }
        }
        return dp[n][m];
    }
    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        // return solveUsingRec(n, m, word1, word2, dp);
        return solveUsingTab(word1, word2);
    }
};