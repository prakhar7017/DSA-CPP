class Solution {
    public int[] twoPointer(int[] nums){
        int n=nums.length;
        int pos=0;
        int neg=1;
        int[] ans=new int[n];
        for(int i=0;i<n;i++){
            int num=nums[i];
            if(num>0){
                ans[pos]=num;
                pos+=2;
            }else {
                ans[neg]=num;
                neg+=2;
            }
        }
        return ans;
    }
    public int[] rearrangeArray(int[] nums) {
        // int n=nums.length;
        // int m=n>>1;
        // int[] pos=new int[m];
        // int[] neg=new int[m];
        // int k=0;
        // int l=0;
        // for(int i=0;i<n;i++){
        //     int num=nums[i];
        //     if(num>0) pos[k++]=num;
        //     else neg[l++]=num;
        // }

        // int[] arr=new int[n];
        // int i=0;
        // int j=0;
        // for(int p=0;p<n;p+=2){
        //     arr[p]=pos[i++];
        //     arr[p+1]=neg[j++];
        // }
        // return arr;
        return twoPointer(nums);

    }
}