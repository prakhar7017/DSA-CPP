// brute force
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

// time complexity:O(n^2logn)
// space complexity:O(n^2)

// uisng priority queue
class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n=arr.size();
        priority_queue<vector<double>>pq;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                double div=(double)arr[i]/arr[j];
                pq.push(vector<double>{div,(double)arr[i],(double)arr[j]});

                if(pq.size()>k){
                    pq.pop();
                }
            }
        }
        auto result=pq.top();
        vector<int>ans(2);
        ans[0]=result[1];
        ans[1]=result[2];
        return ans;
    }
};
// time complexity:O(n^2logk)
// space complexity:O(k)