class Solution {
public:
    int n;
    int solveUsingMemo(int idx, string& s,vector<int>&dp) {
        if (idx >= n)
            return 1;

        if (s[idx] == '0')
            return 0;
        if(dp[idx]!=-1) return dp[idx];    

        int take_one_char = solveUsingMemo(idx + 1, s,dp);
        int take_two_char = 0;
        if (idx + 1 < n) {
            if (s[idx] == '1' || (s[idx] == '2' && s[idx + 1] <= '6'))
                take_two_char = solveUsingMemo(idx + 2, s,dp);
        }
        return dp[idx]=take_one_char+take_two_char;
    }
    int numDecodings(string s) {
        n = s.length();
        vector<int>dp(n+1,-1);
        return solveUsingMemo(0, s,dp);
    }
};