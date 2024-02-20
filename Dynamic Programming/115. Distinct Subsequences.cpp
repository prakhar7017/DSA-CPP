class Solution {
public:
    int solve(string &s, string &t,int i,int j,vector<vector<int>>&dp){
        // base case
        if(j==t.length()){
            return 1;
        }
        if(i==s.length()){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans=0;
        if(s[i]==t[j]){
            ans+=solve(s,t,i+1,j+1,dp);
        }
        ans+=solve(s,t,i+1,j,dp);

        return dp[i][j]=ans;
    }
    int solveUsingTab(string &s,string &t){
        vector<vector<int>>dp(s.length()+1,vector<int>(t.length()+1,0));
        for(int row=0;row<=s.length();row++){
            dp[row][t.size()]=1;
        }
        for(int i=s.length()-1;i>=0;i--){
            for(int j=t.length()-1;j>=0;j--){
                long long ans=0;
                if(s[i]==t[j]){
                    ans+=dp[i+1][j+1];
                }
                ans+=dp[i+1][j];
                dp[i][j]=ans;
            }  
        }
        return dp[0][0];
        
    }
    int spaceOptimised(string &s,string &t){
        vector<int>currRow(t.size()+1,0);
        vector<int>nextRow(t.size()+1,0);
        nextRow[t.size()]=1;
        currRow[t.size()]=1;

        for(int i=s.length()-1;i>=0;i--){
            for(int j=t.length()-1;j>=0;j--){
                long long ans=0;
                if(s[i]==t[j]){
                    ans+=nextRow[j+1];
                }
                ans+=nextRow[j];
                currRow[j]=ans;
            }
            // shifting
            nextRow=currRow;
        }
        return nextRow[0];

    }
    int numDistinct(string s, string t) {
        // vector<vector<int>>dp(s.length()+1,vector<int>(t.length()+1,-1));
        return spaceOptimised(s,t);
    }
};

