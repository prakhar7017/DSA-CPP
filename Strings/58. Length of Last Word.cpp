// 58. Length of Last Word

// Given a string s consisting of words and spaces, return the length of the last word in the string.

// A word is a maximal substring consisting of non-space characters only.

class Solution {
public:
    int lengthOfLastWord(string s) {
        int i=s.length()-1;
        int len=0;
        while(i>=0 && s[i]==' '){
            --i;
        }
        while(i>=0 && s[i]!=' '){
            ++len;
            --i;
        }
        return len;
    }
};

// Time Complexity: O(n)
// Space Complexity: O(1)

// link : https://leetcode.com/problems/length-of-last-word/?envType=daily-question&envId=2024-04-01