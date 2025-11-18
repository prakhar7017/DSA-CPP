class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n = bits.size();
        int consecutive1=0;
        for (int i = n - 2; i >= 0; i--) {
            if(bits[i]==1){
                consecutive1++;
            }else{
                break;
            }
        }
        return ((consecutive1 & 1)==0);
    }
};