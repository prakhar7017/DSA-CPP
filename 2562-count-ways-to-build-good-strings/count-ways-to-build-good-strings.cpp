class Solution {
public:
    int l;
    int h;
    int z;
    int o;
    const int M = 1e9 + 7;
    int solveUsingMemo(int len, vector<int>& dp) {
        if (len > h)
            return 0;
        if (dp[len] != -1)
            return dp[len];
        int ans = 0;
        if (len >= l && len <= h)
            ans += 1;

        int append_zero = solveUsingMemo(len + z, dp);
        int append_one = solveUsingMemo(len + o, dp);

        return dp[len] = (ans + append_zero + append_one) % M;
    }
    int bottomUp(int len) {
        vector<int> dp(h + max(o,z)+1, 0);
        // for(int i=0;i<dp.size();i++){
        //     if(i>=l && i<=h) dp[i]=1;
        // }
        for (int len = h; len >= 0; len--) {
            int ans=0;
            if (len >= l && len <= h)
                ans += 1;

            int append_zero = dp[len + z];
            int append_one = dp[len + o];
            dp[len] = (ans + append_zero + append_one) % M;
        }
        return dp[0];
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        l = low;
        h = high;
        z = zero;
        o = one;
        vector<int> dp(high + 1, -1);
        // return solveUsingMemo(0, dp);
        return bottomUp(h);
    }
};