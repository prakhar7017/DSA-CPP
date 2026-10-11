class Solution {
public:
    
    bool isPalindrome(int i,int j,string&s, vector<vector<bool>>&dp){
        if(i>=j) return true;
        if(dp[i][j]==true) return dp[i][j];
        if(s[i]==s[j]){
            return dp[i][j]=isPalindrome(i+1,j-1,s,dp);
        }
        return dp[i][j]=false;
    }
    int countSubstrings(string s) {
        int n= s.length();
        int count = 0;
        vector<vector<bool>>dp(n,vector<bool>(n,false));
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(isPalindrome(i,j,s,dp)){
                    count++;
                }
            }
        }
        return count;
    }
};