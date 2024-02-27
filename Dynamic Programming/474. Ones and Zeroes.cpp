class Solution {
public:
    void conversion(vector<string>& strs,vector<pair<int,int>>&numStr){
        for(auto str:strs){
            int zeros=0,ones=0;
            for(auto ch:str){
                if(ch=='0')++zeros;
                else ++ones;
            }
            numStr.push_back({zeros,ones});
        }
    }
    int solve(vector<pair<int,int>>&numStr,int i,int m,int n,vector<vector<vector<int>>>&dp){
        // basecase
        if(i>=numStr.size()){
            return 0;
        }
        if(dp[i][m][n]!=-1){
            return dp[i][m][n];
        }
        int ans=INT_MIN;
        int zeros=numStr[i].first;
        int ones=numStr[i].second;
        int include=0;
        int exclude=0;
        if(m-zeros >= 0 && n-ones >= 0){
            include=1+solve(numStr,i+1,m-zeros,n-ones,dp);
        }
        exclude=0+solve(numStr,i+1,m,n,dp);
        return dp[i][m][n]=max(include,exclude);
    }
    int solveTab(vector<pair<int,int>>&numStr,int m,int n){
        vector<vector<vector<int>>>dp(numStr.size()+1,
                                                    vector<vector<int>>(m+1,
                                                                            vector<int>(n+1,0)));
        for(int i=numStr.size()-1;i>=0;i--){
            for(int j=0;j<=m;j++){
                for(int k=0;k<=n;k++){
                    int zeros=numStr[i].first;
                    int ones=numStr[i].second;
                    int include=0;
                    int exclude=0;
                    if(j-zeros >= 0 && k-ones >= 0){
                        include=1+dp[i+1][j-zeros][k-ones];
                    }
                    exclude=0+dp[i+1][j][k]; //solve(numStr,i+1,m,n,dp);
                    dp[i][j][k]=max(include,exclude);
                }
            }
        }
        return dp[0][m][n];
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<pair<int,int>>numStr;
        conversion(strs,numStr);
        // vector<vector<vector<int>>>dp(numStr.size()+1,
        //                                             vector<vector<int>>(m+1,
        //                                                                     vector<int>(n+1,-1)));
        // return solve(numStr,0,m,n,dp);
        return solveTab(numStr,m,n);
    }
};

// time complexity:O(n*m*strs.size())
