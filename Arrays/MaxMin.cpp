class Solution
{
   public:
    int findSum(int A[], int N)
    {
    	int minimum=INT_MAX;
    	int maximum=INT_MIN;
    	for(int i=0;i<N;i++){
    	    minimum=min(minimum,A[i]);
    	    maximum=max(maximum,A[i]);
    	}
    	return minimum+maximum;
    }

};

// time complexity:O(N) 