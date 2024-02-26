class Solution {
public:
    int solveOptimal(vector<int>& arr,vector<int>&lis){
        if(arr.size()==0) return 0;
        vector<int>ans;
        ans.push_back(arr[0]);
        lis.push_back(1); // initial state 
        for(int i=1;i<arr.size();i++){
            if(arr[i]>ans.back()){
                ans.push_back(arr[i]);
                lis.push_back(ans.size());
            }else{
                // just bada element exist
                int index=lower_bound(ans.begin(),ans.end(),arr[i])-ans.begin();
                ans[index]=arr[i];
                lis.push_back(index+1);
            }
        }
        return ans.size();
    }
    int minimumMountainRemovals(vector<int>& nums) {
        vector<int>lis,lds;
        solveOptimal(nums,lis);
        reverse(nums.begin(),nums.end());
        solveOptimal(nums,lds);

        // main logic
        int largestMountain=INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(lis[i]==1 || lds[nums.size()-i-1]==1) continue;
            largestMountain=max(largestMountain,lis[i]+lds[nums.size()-i-1]-1);
        }
        int minRemovals=nums.size()-largestMountain;
        return minRemovals;
    }
};