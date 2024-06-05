/*
    Swapping pairs make sum equal

    Given two arrays of integers a[] and b[] of size n and m, the task is to check if a pair of values (one value from each array) exists such that swapping the elements of the pair will make the sum of two arrays equal.

    Note: Return 1 if there exists any such pair otherwise return -1.

*/
// brute force approach
class Solution {

  public:
    int findSwapValues(int a[], int n, int b[], int m) {
        int s1=accumulate(a,a+n,0);
        int s2=accumulate(b,b+m,0);
        
        if(s1==s2) return 1;
        for(int i=0;i<n;i++){
            for(int j=0;i<m;j++){
                int c1=s1-a[i]+b[j];
                int c2=s2-b[j]+a[i];
                if(c1==c2) return 1;
            }
        }
        return -1;
        
    }
};


// optimal approach
class Solution {

  public:
    bool findPair(int a[], int n, int b[], int m,int target){
        int i=0;
        int j=0;
        while(i<n && j<m){
            int diff=abs(a[i]-b[j]);
            if(diff==target){
                return 1;
            }else if(diff<target){
                ++i;
            }else{
                ++j;
            }
        }
        return 0;
    }
    int findSwapValues(int a[], int n, int b[], int m) {
        sort(a,a+n);
        sort(b,b+m);
        int s1=accumulate(a,a+n,0);
        int s2=accumulate(b,b+m,0);
        
        if(s1==s2) return 1;
        int diff=abs(s1-s2);
        if(diff & 1) return -1;
        int target=diff/2;
        
        if(findPair(a,n,b,m,target)){
            return 1;
        }
        
        return -1;
        
    }

};

// time complexity: O(nlogn+mlogm)
// space complexity: O(1)   
