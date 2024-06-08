/*
    Index of an Extra Element

    You have given two sorted arrays arr1[] & arr2[] of distinct elements. The first array has one element extra added in between. Return the index of the extra element.

    Note: 0-based indexing is followed.

*/


class Solution {
  public:
    int findExtra(int n, int arr1[], int arr2[]) {
        int s=0;
        int e=n-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(arr1[mid]==arr2[mid]){
                s=mid+1;
            }else{
                e=mid-1;
            }
        }
        return e+1;
    }
};

// time complexity : O(logn)
// space complexity : O(1)
