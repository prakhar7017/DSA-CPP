class Solution {
    public long solve(int[] nums){
        int n=nums.length;
        int[] maxLefti= new int[n];
        int[] maxRightk=new int[n];
        maxLefti[0]=0;
        maxRightk[n-1]=0;
        for(int i=1;i<n;i++){
            maxLefti[i]=Math.max(nums[i-1],maxLefti[i-1]);
        }
        for(int i=n-2;i>=0;i--){
            maxRightk[i]=Math.max(nums[i+1],maxRightk[i+1]);
        }
        long ans=0;
        for(int i=1;i<n-1;i++){
            ans=Math.max(ans, (long)(maxLefti[i] - nums[i]) * maxRightk[i]);
        }
        return ans;
    }
    public long maximumTripletValue(int[] nums) {
        return solve(nums);
    }
}