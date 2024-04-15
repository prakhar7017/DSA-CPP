/* 
 Count the elements

 Given two arrays a and b both of size n. Given q queries in an array query each having a positive integer x denoting an index of the array a. For each query, your task is to find all the elements less than or equal to a[x] in the array b.
*/

class Solution {
  public:
    vector<int> countElements(vector<int> &a, vector<int> &b, int n, vector<int> &query,
                              int q) {
        vector<int>ans(q);
        int maxElement=INT_MIN;
        for(int i=0;i<n;i++){
            maxElement=max(maxElement,a[i]);
        }
        
        vector<int>hash(maxElement+1,0);
        
        for(auto i:b){
            if(i<=maxElement){
                hash[i]++;
            }
        }
        
        for(int i=1;i<=maxElement;i++){
            hash[i]+=hash[i-1];
        }
        for(int i=0;i<q;i++){
            ans[i]=hash[a[query[i]]];
        }
        return ans;
    }
};

// time complexity : O(n+maxElement)
// space complexity : O(maxElement)

// link : https://www.geeksforgeeks.org/problems/count-the-elements1529/1