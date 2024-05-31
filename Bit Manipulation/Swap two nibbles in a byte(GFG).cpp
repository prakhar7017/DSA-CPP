/*
    Swap two nibbles in a byte

    Given a number n, Your task is to swap the two nibbles and find the resulting number. 

    A nibble is a four-bit aggregation, or half an octet. There are two nibbles in a byte. For example, the decimal number 150 is represented as 10010110 in an 8-bit byte. This byte can be divided into two nibbles: 1001 and 0110.

*/

// brute force
class Solution {
  public:
    int swapNibbles(int n) {
        vector<int>bitArr(8);
        for(int i=0;i<8;i++){
            bitArr[7-i]=n & 1;
            n=n>>1;
        }
        
        int power=1;
        int sum=0;
        for(int i=3;i>=0;i--){
            sum+=bitArr[i]*power;
            power*=2;
        }
        for(int i=7;i>=4;i--){
            sum+=bitArr[i]*power;
            power*=2;
        }
        return sum;
    }
};

// time complexity: O(1)
// space complexity: O(1)


// Optimized
class Solution {
  public:
    int swapNibbles(int n) {
        int lowerNibble=n&15;
        lowerNibble=lowerNibble<<4;
        
        int upperNibble=n>>4;
        
        return lowerNibble|upperNibble;
    }
};

// time complexity: O(1)
// space complexity: O(1)