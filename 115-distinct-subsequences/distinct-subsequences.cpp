class Solution {
    int mod=1e9+7;
public:
    int solveUsingRec(int n, int m, string& s, string& t,
                      vector<vector<int>>& dp) {
        // basecase
        if (m == 0)
            return 1;
        if (n == 0)
            return 0;
        if (dp[n][m] != -1)
            return dp[n][m];
        int ans = 0;
        if (s[n - 1] == t[m - 1])
            ans += solveUsingRec(n - 1, m - 1, s, t, dp);
        ans += solveUsingRec(n - 1, m, s, t, dp);
        return dp[n][m] = ans;
    }
    int solveUsingTab(string& s, string& t) {
        int n = s.length();
        int m = t.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }
        for (int j = 1; j <= m; j++) {
            dp[0][j] = 0;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                int ans = 0;
                if (s[i - 1] == t[j - 1])
                    ans += dp[i - 1][j - 1];
                ans += dp[i - 1][j];
                dp[i][j]=ans;
            }
        }
        return dp[n][m];
    }
    int solveUsingSpace(string& s, string& t) {
        int n = s.length();
        int m = t.length();
        vector<int>prev(m + 1, 1);
        for (int i = 1; i <= m; i++) {
            prev[i]= 0;
        }
        for (int i = 1; i <= n; i++) {
            vector<int>curr(m+1,1);
            for (int j = 1; j <= m; j++) {
                int ans = 0;
                if (s[i - 1] == t[j - 1])
                    ans += prev[j - 1];
                ans += prev[j];
                curr[j]=ans%mod;
            }
            prev=curr;
        }
        return prev[m];
    }
    int numDistinct(string s, string t) {
        int n = s.length();
        int m = t.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return solveUsingSpace(s, t);
    }
};