class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n=arr.size();

        vector<vector<double>>v;
        vector<int>ans(2);
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                double div=(double)arr[i]/arr[j];
                v.push_back({div,double(arr[i]),double(arr[j])});
            }
        }

        auto lambda=[&](vector<double>&a,vector<double>&b){
            return a[0]<b[0];
        };
        sort(begin(v),end(v),lambda);
        ans[0]=v[k-1][1];
        ans[1]=v[k-1][2];
        return ans;
    }
};