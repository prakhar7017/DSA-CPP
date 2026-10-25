class Solution {
public:
    int n;

    bool solveUsingMemo(int idx, string& s, unordered_set<string>& st,
                        vector<int>& dp) {
        if (idx >= n)
            return true;
        if (st.count(s))
            return true;
        if (dp[idx] != -1)
            return dp[idx];

        for (int l = 1; l <= n - idx; l++) {
            string temp = s.substr(idx, l);
            if (st.count(temp) && solveUsingMemo(idx + l, s, st, dp))
                return dp[idx] = true;
        }
        return dp[idx] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        n = s.length();
        unordered_set<string> st(begin(wordDict), end(wordDict));
        vector<int> dp(n + 1, -1);
        return solveUsingMemo(0,s,st,dp);
    }
};