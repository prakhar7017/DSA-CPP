class Solution {
public:
    int dp[31][1001];
    const int mod = 1e9 + 7;
    int solve(int n, int k, int target){
        // base case
        if(target==0 && n==0) return 1;
        if(target!=0 && n==0) return 0;
        if(target==0 && n!=0) return 0;
        if(dp[n][target]!=-1) return dp[n][target];
        int ans=0;
        for(int i=1;i<=k;i++){
            if(target-i>=0)
                ans=(ans+solve(n-1,k,target-i))%mod;
        }
        return dp[n][target]=ans;
    }
    int numRollsToTarget(int n, int k, int target) {
        //base case
        // if(target<0) return 0;
        // if(n==0 && target!=0) return 0;
        // if(n=0 && target==0) return 1;
        // if(n!=0 && target==0) return 0;

        // int ans=0;
        // for(int i=1;i<=k;i++){
        //     ans=ans+numRollsToTarget(n-1,k,target-i);
        // }
        // return ans;
        memset(dp, -1, sizeof(dp));
        return solve(n,k,target);
    }
};