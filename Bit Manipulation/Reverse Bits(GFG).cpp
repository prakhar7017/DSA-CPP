/*
    Reverse Bits
    Given a number x, reverse its binary form and return the answer in decimal.
*/

class Solution {
  public:
    long long reversedBits(long long x) {
        long long int ans=0,totalBits=32;
        while(totalBits--){ // 32 bits in a number
            int bit=(x&1); // get the last bit of x
            x>>=1; // right shift x by 1 bit to get the next bit in the next iteration 
            ans<<=1; // left shift ans by 1 bit to make space for the next bit
            ans|=bit; // add the bit to ans at the last position 
        }
        return ans;
    }
};

// time complexity : O(32) = O(1)
// space complexity : O(1)