class Solution {
public:
    int recursiveSol(int n){
        if(n==0 || n==1){
            return n;
        }

        return recursiveSol(n-1)+recursiveSol(n-2);
    }


    int solveUsingMemo(int n,vector<int>&dp){
        // base case
        if(n==0 || n==1){
            return n;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        int ans=recursiveSol(n-1)+recursiveSol(n-2);
        return dp[n]=ans;
    }


    int solveTabulation(int n){
        vector<int>dp(n+1,-1);
        dp[0]=0;
        if(n==0){
            return 0;
        }
        dp[1]=1;
        for(int i=2;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }


    int solveSpaceOptimised(int n){
        int prev=0;
        if(n==0 || n==1){
            return n;
        }
        int curr=1;
        int ans;
        for(int i=2;i<=n;i++){
            ans=prev+curr;
            prev=curr;
            curr=ans;
        }
        return ans;
    }

    
    int fib(int n) {
        // int ans= recursiveSol(n);
        // vector<int>dp(n+1,-1);
        int ans=solveSpaceOptimised(n);
        return ans;
    }
};