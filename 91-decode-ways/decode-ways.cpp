class Solution {
public:
    int n;
    int solveUsingMemo(int idx, string& s, vector<int>& dp) {
        if (idx >= n)
            return 1;

        if (s[idx] == '0')
            return 0;
        if (dp[idx] != -1)
            return dp[idx];

        int take_one_char = solveUsingMemo(idx + 1, s, dp);
        int take_two_char = 0;
        if (idx + 1 < n) {
            if (s[idx] == '1' || (s[idx] == '2' && s[idx + 1] <= '6'))
                take_two_char = solveUsingMemo(idx + 2, s, dp);
        }
        return dp[idx] = take_one_char + take_two_char;
    }
    int solveUsingBottomUp(string& s) {
        int n = s.length();
        vector<int> dp(n + 1, 0);
        dp[n] = 1;
        for (int idx = n - 1; idx >= 0; idx--) {
            if (s[idx] == '0') {
                dp[idx] = 0;
            } else {
                int take_one_char = dp[idx + 1];
                int take_two_char = 0;
                if (idx + 1 < n) {
                    if (s[idx] == '1' || (s[idx] == '2' && s[idx + 1] <= '6'))
                        take_two_char = dp[idx + 2];
                }
                dp[idx] = take_one_char + take_two_char;
            }
        }
        return dp[0];
    }
    int numDecodings(string s) {
        n = s.length();
        vector<int> dp(n + 1, -1);
        return solveUsingBottomUp(s);
    }
};