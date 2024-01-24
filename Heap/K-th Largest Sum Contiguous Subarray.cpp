
// brute force
class Solution{
public:
    int kthLargest(vector<int> &Arr,int N,int K){
        vector<int>sumStore;
        for(int i=0;i<N;i++){
            int sum=0;
            for(int j=i;j<N;j++){
                sum+=Arr[j];
                sumStore.push_back(sum);
            }
        }
        sort(sumStore.begin(),sumStore.end());
        return sumStore[sumStore.size()-K];
    }
};
// Time complexity :o(n^2logn)
// space complexity:o(n^2)