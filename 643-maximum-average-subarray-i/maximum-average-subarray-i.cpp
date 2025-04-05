class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n=nums.size();
        int startIndex=0;
        int endIndex=k-1;
        double sum=0;
        double maxSum=0;

        for(int i=0;i<=endIndex;i++){
            sum+=nums[i];
            maxSum=sum;
        }

        endIndex++;
        while(endIndex<n){
            sum=sum-nums[startIndex++]+nums[endIndex++]; //window slided
            maxSum=max(maxSum,sum);
        }

        return maxSum/k;
    }
};