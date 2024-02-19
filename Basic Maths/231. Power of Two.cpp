class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0){
            return false;
        }
        if(n==1){
            return true;
        }
        while(n>0){
            if(n%2==0 || n==1){
                n=n/2;
            }else{
                return false;
            }
        }
        return true;
    }
};

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0){
            return false;
        }
        if(n==1) return true;
        return n%2 == 0 && isPowerOfTwo(n/2); 
    }
};

// bit magic
// if n is power of 2 then n & n-1 will be 0 because n-1 will have all 1s and n will have 1 at the position of 0 in n-1
// for eg n=4 => 100           n=8 => 1000
//        n-1=3 => 011         n-1 => 0111
//        n & n-1 => 000       n & n-1 => 0000
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0) return false;
        if((n & n-1)==0){
            return true;
        }
        return false;
    }
};

// built in function

// __builtin_popcount(n) returns the number of set bits in n
// if n is power of 2 then it will have only 1 set bit
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0) return false;
        if((__builtin_popcount(n))==1){
            return true;
        }
        return false;
    }
};