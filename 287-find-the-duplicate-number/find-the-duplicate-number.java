class Solution {
    public void swap(int[] nums,int i,int j){
        int temp=nums[i];
        nums[i]=nums[j];
        nums[j]=temp;
    }
    public int elementIndexSwap(int[] nums){
        int index=nums[0];
        while(nums[0]!=nums[nums[0]]){
            swap(nums,0,nums[0]);
        }
        return nums[0];
    }
    public int elementAsIndex(int[] nums){
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
    public int findDuplicate(int[] nums) {
        return elementIndexSwap(nums);
    }
}