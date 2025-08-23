class Solution {
public:
    bool solveUsingRec(int n, int m, string& s, string& p,
                       vector<vector<int>>& dp) {
        // basecase
        if (n == 0 && m == 0)
            return true;
        if (n > 0 && m == 0)
            return false;
        if (n == 0 && m > 0) {
            for (int i = 0; i < m; i++) {
                if (p[i] != '*')
                    return false;
            }
            return true;
        }
        if (dp[n][m] != -1)
            return dp[n][m];
        if (s[n - 1] == p[m - 1] || p[m - 1] == '?') {
            return dp[n][m] = solveUsingRec(n - 1, m - 1, s, p, dp);
        } else if (p[m - 1] == '*') {
            return dp[n][m] = solveUsingRec(n, m - 1, s, p, dp) ||
                              solveUsingRec(n - 1, m, s, p, dp);
        }
        return dp[n][m] = false;
    }

    bool solveUsingTab(string& s, string& p) {
        int n = s.length();
        int m = p.length();
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
        dp[0][0] = true;
        for (int i = 1; i <= n; i++)
            dp[i][0] = false;
        for (int j = 1; j <= m; j++) {
            bool flag = true;
            for (int i = 0; i < j; i++) {
                if (p[i] != '*') {
                    flag = false;
                    break;
                }
            }
            dp[0][j] = flag;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s[i - 1] == p[j - 1] || p[j - 1] == '?') {
                    dp[i][j] = dp[i - 1][j - 1];
                } else if (p[j - 1] == '*') {
                    dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
                } else {
                    dp[i][j] = false;
                }
            }
        }
        return dp[n][m];
    }
    bool isMatch(string s, string p) {
        int n = s.length();
        int m = p.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        // return solveUsingRec(n, m, s, p, dp);
        return solveUsingTab(s, p);
    }
};