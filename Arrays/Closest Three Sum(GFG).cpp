class Solution {
  public:
    int threeSumClosest(vector<int> arr, int target) {
        int n=arr.size();
        int diff=INT_MAX;
        int maxi=INT_MIN;
        sort(begin(arr),end(arr));
        
        for(int fix=0;fix<=n-3;fix++){
            int i=fix+1;
            int j=n-1;
            while(i<j){
                int sum=arr[fix]+arr[i]+arr[j];
                int temp=abs(target-sum);
                
                if(temp==diff){
                    maxi=max(sum,maxi);
                }else if(temp<diff) maxi=sum, diff=temp;
                
                if(sum<target) i++;
                else j--;
            }
        }
        return maxi;
    }
};

// time complexity:o(n^2);
// space complexity:o(1);
