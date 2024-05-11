/*
    Juggler Sequence

    Juggler Sequence is a series of integers in which the first term starts with a positive integer number a and the remaining terms are generated from the immediate previous term using the below recurrence relation:

    a_(n+1) = a_n^(1/2) if a_n is even
    a_(n+1) = a_n^(3/2) if a_n is odd

*/

class Solution {
  public:
    vector<long long> jugglerSequence(long long n) {
        vector<long long>ans;
        ans.push_back(n);
        while(n!=1){
            if(n & 1){ // odd number
                n=(n*sqrt(n));
                ans.push_back(n);
            }else{
                // even n
                n=sqrt(n);
                ans.push_back(n);
            }
        }
        return ans;
    }
};

// time complexity: O(logn)
// space complexity: O(logn)

// link : https://www.geeksforgeeks.org/problems/juggler-sequence3930/1

