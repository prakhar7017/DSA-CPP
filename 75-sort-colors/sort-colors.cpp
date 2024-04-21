class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        
        int l=0;
        int idx=0;
        int r=n-1;
        
        while(idx<=r){
            if(nums[idx]==0){
                swap(nums[idx++],nums[l++]);
            }else if(nums[idx]==2){
                swap(nums[idx],nums[r--]); // yha galti karuga . 
            }else{
                ++idx;
            }
        }

    }
};