class Solution {
public:
    int n;
    bool isPalindrome(int i,int j, string&s,vector<vector<int>>&dp){
        if(i>j) return true;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==s[j]){
            return dp[i][j]=isPalindrome(i+1,j-1,s,dp);
        }
        return dp[i][j]=false;
    }
    string longestPalindrome(string s) {
        n=s.length();
        int maxLen=0;
        int startIndex=0;
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(isPalindrome(i,j,s,dp) && j-i+1>maxLen){
                    maxLen = j-i+1;
                    startIndex = i;
                }
            }
        }
        return s.substr(startIndex,maxLen);
    }
};