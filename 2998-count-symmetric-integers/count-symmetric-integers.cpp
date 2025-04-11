class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
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
};