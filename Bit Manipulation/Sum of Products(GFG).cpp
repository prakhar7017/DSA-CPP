/*
    Sum of Products

    Given an array arr[] of size n. Calculate the sum of Bitwise ANDs ie: calculate sum of arr[i] & arr[j] for all the pairs in the given array arr[] where i < j.
*/

class Solution {
  public:
    long long pairAndSum(int n, long long arr[]) {
        long long ans=0;
        for(int i=0;i<32;i++){
            long long k=0;
            for(int j=0;j<n;j++){
                if((arr[j]&(1<<i))!=0){
                    //set bit hh
                    ++k;
                }
            }
            ans+=(1<<i)*((k)*(k-1))/2;
        }
        return ans;
    }
};

// time complexity : O(32*n)
// space complexity : O(1)