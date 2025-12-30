class Solution {
public:
    int findLeftMost(vector<int>& nums, int target){
        int s = 0;
        int e = nums.size()-1;
        int ans = -1;
        while(s<=e){
            int mid = s+(e-s)/2;
            if(nums[mid]<target){
                s = mid+1; 
            } else if(nums[mid]>target){
                e = mid-1;
            } else {
                ans = mid;
                e = mid-1;
            }
        }
        return ans;
    }
    int findRightMost(vector<int>& nums, int target){
        int s = 0;
        int e = nums.size()-1;
        int ans = -1;
        while(s<=e){
            int mid = s+(e-s)/2;
            if(nums[mid]<target){
                s = mid+1; 
            } else if(nums[mid]>target){
                e = mid-1;
            } else {
                ans = mid;
                s = mid+1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>ans;
        int left = findLeftMost(nums,target);
        int right = findRightMost(nums,target);
        ans.push_back(left);
        ans.push_back(right);
        return ans;
    }
};