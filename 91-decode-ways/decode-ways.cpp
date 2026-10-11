class Solution {
public:
    int solve(int i, int n, string& s,vector<int>&dp) {
        if(dp[i]!=-1) return dp[i];
        if (i == n)
            return dp[i]=1;

        if (s[i] == '0')
            return dp[i]=0;

        int ith_char = solve(i + 1, n, s,dp);
        int ith_char_plus_one = 0;
        if (i + 1 < n) {
            if (s[i] == '1' || (s[i] == '2' && s[i + 1] <= '6'))
                ith_char_plus_one = solve(i + 2, n, s,dp);
        }

        return dp[i]=ith_char + ith_char_plus_one;
    }
    int bottomUp(string &s){
        int n = s.length();
        vector<int>dp(n+1,-1);
        dp[n]=1;
        for(int i = n-1;i>=0;i--){
            if(s[i]=='0') dp[i] = 0;
            else {
                dp[i]= dp[i+1];

                if(i+1<n){
                    if(s[i]=='1' || (s[i]=='2' && s[i+1] <= '6'))
                        dp[i]+=dp[i+2];
                }
            }
        }
        return dp[0];
    }
    int numDecodings(string s) {
        int n = s.length();
        vector<int>dp(n+1,-1);
        return bottomUp(s);
    }
};