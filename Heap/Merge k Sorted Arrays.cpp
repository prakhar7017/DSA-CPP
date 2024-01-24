// Brute Force 
class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        vector<int>v;
        int n=arr.size();
        for(int i=0;i<n;i++){
            int rowS=arr[i].size();
            for(int j=0;j<rowS;j++){
                v.push_back(arr[i][j]);
            }
        }
        sort(v.begin(),v.end());
        return v;
    }
};

