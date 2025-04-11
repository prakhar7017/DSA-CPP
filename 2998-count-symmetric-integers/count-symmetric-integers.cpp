class Solution {
public:
    int solveBruteForce(int low, int high){
        int ans=0;
        for(int num=low;num<=high;num++){
            string str=to_string(num);
            int len=str.length();
            if(len&1) continue;
            int leftSum=0;
            int rightSum=0;

            for(int i=0;i<len/2;i++){
                leftSum+=str[i]-'0';
            }
            for(int i=len/2;i<len;i++){
                rightSum+=str[i]-'0';
            }

            if(leftSum==rightSum) ans++;
        }
        return ans;
    }
    int solveOptmised(int low, int high){
        int ans=0;
        for(int num=low;num<=high;num++){
            if((num>=11) && (num<=99) && ((num%11)==0)) ans++;
            else if ((num>=1000) && (num<=9999)) {
                int first=num/1000;
                int second=(num/100)%10;
                int third=(num/10)%10;
                int fourth=num%10;

                if(first+second==third+fourth) ans++;
            }
        }
        return ans;
    }
    int countSymmetricIntegers(int low, int high) {
        return solveOptmised(low,high);
    }
};