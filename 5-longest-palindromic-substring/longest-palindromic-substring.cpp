class Solution {
public:
    bool isPalindrome(int i, int j, string& s, vector<vector<bool>>& dp) {
        if (i >= j)
            return true;
        if (dp[i][j])
            return true;
        if (s[i] == s[j]) {
            if (isPalindrome(i + 1, j - 1, s, dp))
                return dp[i][j] = true;
        }
        return dp[i][j] = false;
    }
    string bottomUp(string s) {
        int n = s.length();
        int maxLen = 1;
        int sp = 0;
        vector<vector<bool>> dp(n + 1, vector(n + 1, false));
        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
        }
        for(int i=n-1;i>=0;i--){
            for(int j=i;j<n;j++){
                if(s[i]==s[j]){
                    if(j-i<=1){
                        dp[i][j]=true;
                    }else{
                        dp[i][j] = dp[i+1][j-1];
                    }
                }

                if(dp[i][j] && j-i+1>maxLen){
                    sp=i;
                    maxLen = j-i+1;
                }
            }
        }
        return s.substr(sp,maxLen);
    }
    string longestPalindrome(string s) {
        return bottomUp(s);
        // int n = s.length();
        // int maxLen = INT_MIN;
        // int sp = 0;
        // vector<vector<bool>> dp(n + 1, vector(n + 1, false));
        // for (int i = 0; i < n; i++) {
        //     for (int j = i; j < n; j++) {
        //         if (isPalindrome(i, j, s, dp) && j - i + 1 > maxLen) {
        //             maxLen = j - i + 1;
        //             sp = i;
        //         }
        //     }
        // }
        // return s.substr(sp, maxLen);
    }
};