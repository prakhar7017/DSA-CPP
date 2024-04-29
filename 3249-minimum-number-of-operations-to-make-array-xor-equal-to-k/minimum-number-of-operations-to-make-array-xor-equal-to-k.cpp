class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int totalXOR=0;

        for(int num:nums){
            totalXOR^=num;
        }

        int bitsDontMatch=totalXOR^k;

        int countBitsDontMatch=__builtin_popcount(bitsDontMatch);

        return countBitsDontMatch;
    }
};