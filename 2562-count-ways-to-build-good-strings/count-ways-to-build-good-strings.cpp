class Solution {
public:
    int l;
    int h;
    int z;
    int o;
    const int M = 1e9+7;
    int solveUsingMemo(int len,vector<int>&dp){
        if(len>h) return 0;
        if(dp[len]!=-1) return dp[len];
        int ans=0;
        if(len>=l && len<=h) ans+=1;

        int append_zero = solveUsingMemo(len+z,dp);
        int append_one  = solveUsingMemo(len+o,dp);

        return dp[len]=(ans+append_zero+append_one)%M;
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        l=low;
        h=high;
        z=zero;
        o=one;
        vector<int>dp(high+1,-1);
        return solveUsingMemo(0,dp);
    }
};