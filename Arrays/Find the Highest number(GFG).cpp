/*
    Find the Highest number

    Given an integer array a[] of size n, find the highest element of the array. The array will either be strictly increasing or strictly increasing and then strictly decreasing.

    Note: a[i] != a[i+1] 

*/

class Solution {
public:
    int findPeakElement(vector<int>& a) 
    {
        int s=0;
        int e=a.size()-1;
        while(s<e){
            int mid=s+(e-s)/2;
            if(a[mid]<a[mid+1]){ // A
                s=mid+1;
            }else{ // B or Peak
                e=mid;
            }
        }
        return a[e];
    }
};

// time complexity: O(logn)
// space complexity: O(1)
