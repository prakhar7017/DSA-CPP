class Solution{
    private:
    long long solve(vector<long long>arr,long long &n,long long &m){
        if(n==0 || m==0){
            return 0;
        }
        if(m>n){
            return 0;
        }
        sort(arr.begin(),arr.end());
        long long mindiff=INT_MAX;
        for(int i=0;i+m-1<n;i++){
            long long diff=arr[i+m-1]-arr[i];
            mindiff=diff<mindiff ? diff : mindiff;
        }
        return mindiff;
    }
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
        return solve(a,n,m);
    }   
};

// time complexity:O(nlogn) space complexity:O(1)