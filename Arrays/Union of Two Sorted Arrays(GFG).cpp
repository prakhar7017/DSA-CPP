/*
    Union of Two Sorted Arrays
    Given two sorted arrays of size n and m respectively, find their union. The Union of two arrays can be defined as the common and distinct elements in the two arrays. 
*/
class Solution{
    public:
    //arr1,arr2 : the arrays
    // n, m: size of arrays
    //Function to return a list containing the union of the two arrays. 
    vector<int> findUnion(int arr1[], int arr2[], int n, int m)
    {
        int i=0;
        int j=0;
        vector<int>ans;
        while(i<n && j<m){
            
            if(i>0 && arr1[i]==arr1[i-1]){
                ++i;
                continue;
            }
            
            if(j>0 && arr2[j]==arr2[j-1]){
                ++j;
                continue;
            }
            
            if(arr1[i]<arr2[j]){
                ans.push_back(arr1[i++]);
            } else if(arr2[j]<arr1[i]){
                ans.push_back(arr2[j++]);
            }else{
                ans.push_back(arr1[i]);
                ++i;
                ++j;
            }
        }
        while(i<n){
            if(i>0&&arr1[i]!=arr1[i-1]){
                ans.push_back(arr1[i]);
            }
            i++;
        }
        while(j<m){
            if(j>0 && arr2[j]!=arr2[j-1]){
                ans.push_back(arr2[j]);
            }
            j++;
        }
        return ans;
    }
};

// time complexity : O(n+m)
// space complexity : O(1)