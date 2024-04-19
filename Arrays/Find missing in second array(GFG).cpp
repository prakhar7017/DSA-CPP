/*
    Find missing in second array

    Given two integer arrays a of size n and b of size m, the task is to find the numbers which are present in the first array a, but not present in the second array b.

*/

class Solution{
	
	
	public:
	vector<int> findMissing(int a[], int b[], int n, int m) 
	{ 
	    vector<int>ans;
	    unordered_set<int>st;
	    for(int i=0;i<m;i++){
	        st.insert(b[i]);
	    }
	    
	    for(int i=0;i<n;i++){
	        if(st.find(a[i])==st.end()){
	            ans.push_back(a[i]);
	        }
	    }
	    return ans;
	} 
};

// time complexity : O(n+m)
// space complexity : O(m)