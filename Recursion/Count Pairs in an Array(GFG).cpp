/*
    Count Pairs in an Array

    Given an array arr of n integers, count all pairs (arr[i], arr[j]) in it such that i*arr[i] > j*arr[j] and 0 ≤ i < j < n.

    Note: 0-based Indexing is followed.

*/

class Solution{
    public:
    
    long long merge(int arr[],int s,int mid,int e){
        int lenLeft=mid-s+1;
        int lenRight=e-mid;
        
        int* left=new int[lenLeft];
        int* right=new int[lenRight];
        
        int k=s;
        for(int i=0;i<lenLeft;i++){
            left[i]=arr[k++];
        }
        k=mid+1;
        for(int i=0;i<lenRight;i++){
            right[i]=arr[k++];
        }
        
        int leftIndex=0;
        int rightIndex=0;
        int mainIndex=s;
        long long c=0;
        while(leftIndex<lenLeft && rightIndex<lenRight){
            if(left[leftIndex]<=right[rightIndex]){
                arr[mainIndex++]=left[leftIndex++];
            }else{
                arr[mainIndex++]=right[rightIndex++];
                c+=lenLeft-leftIndex; // this is the main part of the code which is counting the pairs
            }
        }
        while(leftIndex<lenLeft){
            arr[mainIndex++]=left[leftIndex++];
        }
        while(rightIndex<lenRight){
             arr[mainIndex++]=right[rightIndex++];
        }
        delete[] left;
        delete[] right;
        return c;
    }
    long long getPairs(int arr[],int s,int e){
        // base case
        if(s>=e) return 0;
        
        int mid=s+(e-s)/2;
        long long c=0;
        c+=getPairs(arr,s,mid);
        c+=getPairs(arr,mid+1,e);
        c+=merge(arr,s,mid,e);
        return c;
    }
    int countPairs(int arr[] , int n ) 
    {
        for(int i=0;i<n;i++){
            arr[i]=i*arr[i];
        }
        
        long long ans=getPairs(arr,0,n-1);
        return ans;
    }
};

// time complexity: O(nlogn)
// space complexity: O(n)