class Solution {
public:
    int solveFindMinBS(vector<int>& nums){
        int s = 0;
        int e = nums.size() - 1;
        while(s<e){
            int mid = s+(e-s)/2;

            if(nums[mid]>nums[e]) s = mid + 1;
            else e = mid;
        }
        return e;
    }
    int binarySearch(vector<int>& nums, int target, int s , int e){
        while(s<=e){
            int mid = s+(e-s)/2;
            if(nums[mid]==target) return mid;
            else if(nums[mid]<target){
                s = mid + 1;
            }else{
                e = mid - 1;
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int pivot = solveFindMinBS(nums);
        int leftSortedAns = binarySearch(nums,target,0,pivot-1);
        int rightSortedAns = binarySearch(nums,target,pivot,nums.size()-1);
        if(leftSortedAns!= -1) return leftSortedAns;
        return rightSortedAns;
    }
};