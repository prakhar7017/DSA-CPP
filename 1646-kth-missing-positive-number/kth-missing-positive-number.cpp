class Solution {
public:
    int solve(vector<int>& arr, int k) {
        int n = arr.size();
        int num = 1;
        int i = 0;
        while (i < n && k > 0) {
            if (arr[i] == num) {
                i++;
            } else {
                k--;
            }
            num++;
        }

        while (k--) {
            num++;
        }
        return num - 1;
    }
    int solveUsingBS(vector<int>& arr, int k){
        int n = arr.size();
        int s = 0;
        int e = n-1;

        while(s<=e){
            int mid = s+(e-s)/2;
            int no_missing_elements = arr[mid]-(mid+1);

            if(no_missing_elements<k){
                s = mid +1;
            }else{
                e = mid - 1;
            }
        }

        return s+k;
    }
    int findKthPositive(vector<int>& arr, int k) {
        return solveUsingBS(arr,k);
    }
};