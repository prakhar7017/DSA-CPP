class Solution {
    public int reverse(int x) {
        int minValue=Integer.MIN_VALUE; // -2147483648
        int maxValue=Integer.MAX_VALUE; //  2147483648
        int ans=0;
        while(x!=0){
            if((ans>maxValue/10) || (ans<minValue/10)) return 0; // check if ans is going out of range.
            ans=(ans*10)+(x%10);
            x/=10;
        }
        return ans;
    }
}