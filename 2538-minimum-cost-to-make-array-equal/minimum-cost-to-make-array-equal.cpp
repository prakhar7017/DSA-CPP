class Solution {
public:
    long long calculateMaxCost(int n,int mid,vector<int>& nums, vector<int>& cost){
        long long result = 0;
        for(int i=0;i<n;i++){
            result += (long long) abs(nums[i]-mid) * cost[i];
        }
        return result;
    }
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int n = nums.size();
        int right = *max_element(begin(nums),end(nums));
        int left = *min_element(begin(nums),end(nums));
        long long ans = INT_MAX;
        while(left<=right){
            int mid = left + (right-left)/2;

            long long cost1 = calculateMaxCost(n,mid,nums,cost);
            long long cost2 = calculateMaxCost(n,mid+1,nums,cost);
            ans = min(cost1,cost2);
            if(cost2>cost1){
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};