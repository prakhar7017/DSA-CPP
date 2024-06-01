/*
    Odd Even Problem
    Given a string s of lowercase English characters, determine whether the summation of x and y is EVEN or ODD.

    where:
    x is the count of distinct characters that occupy even positions in the English alphabet and have even frequency. 
    y is the count of distinct characters that occupy odd positions in the English alphabet and have odd frequency.
    Ex: string = "ab" here 'a' has an odd(1) position in the English alphabet & has an odd(1) frequency in the string so a is odd but b has an even(2) position in the English alphabet & has odd(1) frequency so it doesn't count(since string doesn't have 2 b's) so the final answer x + y = 1+0 = 1(odd) would be "ODD".

    Note: Return "EVEN" if the sum of x & y is even otherwise return "ODD".

*/

class Solution {
  public:
    string oddEven(string s) {
        vector<int>freq(26);
        int n=s.length();
        
        for(int i=0;i<n;i++){
            freq[s[i]-'a']++;
        }
        int count=0;
        
        for(int i=0;i<26;i++){
            if(freq[i]>0){
                // position
                if((i+1)&1){
                    // odd posi
                    if(freq[i] & 1){
                        ++count;
                    }
                }else{
                    // even posi
                    if((freq[i]&1)==0){
                        ++count;
                    }
                }
            }
        }
        
        return count&1 == 1 ? "ODD" : "EVEN" ;
    }
};

// Time Complexity: O(N)
// Space Complexity: O(1)
