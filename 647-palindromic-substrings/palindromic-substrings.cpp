class Solution {
public:
    // bool check(int i,int j, string& s,vector<vector<int>>& dp){
    //     if(i>j) return true;
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     if(s[i]==s[j]) return dp[i][j]=check(i+1,j-1,s,dp);
    //     return dp[i][j]=false;
    // }
    int countSubstrings(string s) {
        int n= s.length();
        // vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        // int count=0;
        // for(int i=0;i<n;i++){
        //     for(int j=i;j<n;j++){
        //         if(check(i,j,s,dp)) count++;
        //     }
        // }
        // return count;

        int count=0;
        vector<vector<bool>>dp(n+1,vector<bool>(n+1,false));
        for(int L=1;L<=n;L++){
            for(int i=0;i+L-1<n;i++){
                int j=i+L-1;
                if(i==j){
                    dp[i][j]=true;
                }else if(i+1==j){
                    dp[i][j]=(s[i]==s[j]);
                }else{
                    dp[i][j]=(s[i]==s[j] && dp[i+1][j-1]);
                }

                count+=dp[i][j];
            }
        }
        return count;
    }
};