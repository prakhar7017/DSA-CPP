class Solution {
    int arr[10001];
    private:
    int numSquaresHelper(int n){
        // base case
        if(n==0){
            return 0;
        }
        if(arr[n]!=-1){
            return arr[n];
        }
        // processing
        int ans=INT_MAX;
        int i=1;
        while((i*i)<=n){
            int perfectSqaure=i*i;
            int result=1+numSquaresHelper(n-perfectSqaure);
            ans=min(ans,result);
            i++;
        }
        return arr[n]=ans;
    }
public:
    int numSquares(int n) {
        memset(arr,-1,sizeof(arr));
        return numSquaresHelper(n);
    }
};

// Bottom Up
int numSquaresHelperTab(int n){
        vector<int>dp(n+1,INT_MAX);
        dp[0]=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j*j<=i;j++){
                dp[i]=min(dp[i],1+dp[i-j*j]);
            }
        }
        return dp[n];
}