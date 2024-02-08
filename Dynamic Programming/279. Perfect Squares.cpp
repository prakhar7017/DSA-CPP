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