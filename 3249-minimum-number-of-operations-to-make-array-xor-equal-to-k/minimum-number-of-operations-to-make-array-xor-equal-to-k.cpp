class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int totalXOR=0; // XOR of all elements in nums

        for(int num:nums){
            totalXOR^=num; // XOR of all elements in nums
        }

        int bitsDontMatch=totalXOR^k; // XOR of all elements in nums and k which gives the bits dont match at every position
        // for eg k=1-> 0 0 1
        // totalXOR=4-> 1 0 0
// bitsDontMatch=1^4->  1 0 1  , first and last bits dont match that why there is 1 at first and last position

        int countBitsDontMatch=__builtin_popcount(bitsDontMatch); // count the number of bits dont match

        return countBitsDontMatch;
    }
};

// time complexity: O(n)
// space complexity: O(1)