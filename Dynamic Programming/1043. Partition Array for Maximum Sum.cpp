class Solution {
public:
    int v[501];
    int solve(vector<int>& arr, int &k,int i){
        // base case
        if(i>=arr.size()){
            return 0;
        }
        if(v[i]!=-1){
            return v[i];
        }
        int result=0;
        int currMax=-1;
        for(int j=i;j<arr.size() && j-i+1<=k;j++){
            currMax=max(currMax,arr[j]);
            result=max(result,(j-i+1)*currMax+solve(arr,k,j+1));
        }

        return v[i]=result;

    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int i=0;
        memset(v,-1,sizeof(v));
        return solve(arr,k,i);
    }
};