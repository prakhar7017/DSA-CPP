class Solution {
    public int solve(int[] nums){
        int n=nums.length;
        int[] leftsum=new int[n];
        int[] rightsum=new int[n];

        leftsum[0]=0;
        rightsum[n-1]=0;
        for(int i=1;i<n;i++){
            leftsum[i]=leftsum[i-1]+nums[i-1];
        }
        for(int i=n-2;i>=0;i--){
            rightsum[i]=rightsum[i+1]+nums[i+1];
        }
        for(int i=0;i<n;i++){
            if(leftsum[i]==rightsum[i]) return i;
        }
        return -1;
    }
    public int pivotIndex(int[] nums) {
        // int n=nums.length;

        // for(int i=0;i<n;i++){
        //     int leftsum=0;
        //     int rightsum=0;
        //     for(int j=0;j<i;j++){
        //         leftsum+=nums[j];
        //     }
        //     for(int j=i+1;j<n;j++) rightsum+=nums[j];
        //     if(leftsum==rightsum) return i;
        // }
        // return -1;
        return solve(nums);
    }
}