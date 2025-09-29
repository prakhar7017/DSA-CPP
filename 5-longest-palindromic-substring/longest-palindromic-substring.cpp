class Solution {
public:
    bool check(int start,int end,string& s,vector<vector<int>>& dp){
        if(start>end) return true;
        if(dp[start][end]!=-1) return dp[start][end];
        if(s[start]==s[end]) return dp[start][end]=check(start+1,end-1,s,dp);
        return dp[start][end]=false;
    }
    string solveUsingBruteForce(string& s){
        int n = s.length();
        int maxLen=0;
        int start=0;
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(check(i,j,s,dp)){
                    if(j-i+1>maxLen){
                        maxLen=j-i+1;
                        start=i;
                    }
                }
            }
        }
        return s.substr(start,maxLen);
    }

    string solveUsingOptimised(string& s){
        int n = s.length();
        int maxLen=0;
        int start=0;
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));

        for(int Len=1;Len<=n;Len++){
            for(int i=0;i+Len-1<n;i++){
                int j = i+Len-1;
                if(i==j) dp[i][j]=true;
                else if(i+1==j){
                    dp[i][j]=(s[i]==s[j]);
                }else{
                    dp[i][j]=(s[i]==s[j] && dp[i+1][j-1]);
                }

                if(dp[i][j]){
                    if(j-i+1>maxLen){
                        maxLen = j-i+1;
                        start=i;
                    }
                }
            }
        }

        return s.substr(start,maxLen);
    }
    string longestPalindrome(string s) {
        // return solveUsingBruteForce(s);
        return solveUsingOptimised(s);
    }
};