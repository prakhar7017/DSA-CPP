class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long XOR = 0;
        for(int num:nums){
            XOR^=num;
        }

        int mask=(XOR)&(-XOR);

        int groupA=0;
        int groupB=0;

        for(int num:nums){
            if(num&mask){
                groupA^=num;
            }else{
                groupB^=num;
            }
        }

        return {groupA,groupB};
    }
};