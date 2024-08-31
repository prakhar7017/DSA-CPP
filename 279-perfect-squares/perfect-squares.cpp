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
        int ans=INT_MAX;
        int i=1;
        while((i*i)<=n){
            int perfectSqare=i*i;
            int result=1+numSquaresHelper(n-perfectSqare);
            ans=min(ans,result);
            i++;
        }
        return arr[n]=ans;
    }
    int solve(int n){
        // base case
        if(n<=0) return 0;
        if(arr[n]!=-1) return arr[n];
        int ans=INT_MAX;
        for(int i=1;i*i<=n;i++){
            int rec=1+solve(n-(i*i));
            ans=min(ans,rec);
        }
        return arr[n]=ans;
    }
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
    // int numSquaresHelper(int n){
    //     // base case
    //     if(n==0){
    //         return 0;
    //     }
    //     if(arr[n]!=-1){
    //         return arr[n];
    //     }
    //     // processing
    //     int ans=INT_MAX;
    //     int i=1;
    //     while((i*i)<=n){
    //         int perfectSqaure=i*i;
    //         int result=1+numSquaresHelper(n-perfectSqaure);
    //         ans=min(ans,result);
    //         i++;
    //     }
    //     return arr[n]=ans;
    // }
    // int numSquaresHelper(int n){
    //     // base case
    //     if(n==0) return 1;
    //     if(n<0) return 0;

    //     //processing
    //     int ans=INT_MAX;
    //     int end=sqrt(n);
    //     while(int i<=end){
    //         int perfectSquare=i*i;
    //         int numberOfPerfectSquare=1+numSquaresHelper(n-perfectSquare);
    //         if(numberOfPerfectSquare<ans){
    //             ans=numberOfPerfectSquare;
    //         }
    //         i++;
    //     }
    //     return ans;
    // }
public:
    int numSquares(int n) {
        // memset(arr,-1,sizeof(arr));
        // return numSquaresHelperTab(n);
        memset(arr,-1,sizeof(arr));
        return solve(n);
    }
};