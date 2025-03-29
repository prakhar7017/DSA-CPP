class Solution {
    public void swap(int[] nums,int a,int b){
        int temp=nums[a];
        nums[a]=nums[b];
        nums[b]=temp;
    }
    public void sortColors(int[] nums) {
        int left=0;
        int right=nums.length-1;
        int index=0;
        while(index<=right){
            if(nums[index]==0){
                swap(nums,left++,index++);
            }else if(nums[index]==2){
                swap(nums,right--,index);
            }else{
                index++;
            }
        }
    }
}