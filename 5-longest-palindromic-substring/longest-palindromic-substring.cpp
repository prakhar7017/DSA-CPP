class Solution {
public:
    bool isPalindrome(int i,int j,string&s,vector<vector<bool>>&dp){
        if(i>=j) return true;
        if(dp[i][j]==true) return dp[i][j];
        if(s[i]==s[j]){
            return dp[i][j]=isPalindrome(i+1,j-1,s,dp);
        }
        return dp[i][j]=false;
    }
    string longestPalindrome(string s) {
        int n = s.length();
        int maxLen = INT_MIN;
        int sp=0;
        vector<vector<bool>>dp(n,vector<bool>(n,false));
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(isPalindrome(i,j,s,dp) && j-i+1>maxLen){
                    maxLen= j-i+1;
                    sp=i;
                }
            }
        }

        return s.substr(sp,maxLen);
    }
};