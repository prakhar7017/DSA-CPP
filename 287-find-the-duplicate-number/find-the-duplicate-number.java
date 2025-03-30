class Solution {
    public int findDuplicate(int[] nums) {
        int n=nums.length;
        int ans=-1;
        for(int i=0;i<n;i++){
            int index=Math.abs(nums[i]);
            if(nums[index]<0){
                ans=index;
                break;
            }
            nums[index]*=-1;
        }
        return ans;
    }
}