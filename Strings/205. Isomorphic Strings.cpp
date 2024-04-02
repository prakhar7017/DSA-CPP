205. Isomorphic Strings
Given two strings s and t, determine if they are isomorphic.

Two strings s and t are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.


class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length()!=t.length()) return false;
        int hash[256]={0}; // starting ma s ke sare char unmapped hh
        bool isTcharMapped[256]={false}; // starting ma t ke sare char unmapped hh

        for(int i=0;i<s.length();i++){
            if(hash[s[i]]==0 && isTcharMapped[t[i]]==false){ // agar s[i] pehle se mapped nhi hh and t[i] pehle se mapped nhi hh
                hash[s[i]]=t[i]; // s[i] ko t[i] sa map keya
                isTcharMapped[t[i]]=true;// t[i] ko mapped keya
            }
        }
        for(int i=0;i<s.size();i++){
            if((char)hash[s[i]]!=t[i]) return false; // agar s[i] ka map t[i] nhi hh toh false return keya
        }
        return true;

    }
};

// Time Complexity: O(n)
// Space Complexity: O(1)

// link : https://leetcode.com/problems/isomorphic-strings/?envType=daily-question&envId=2024-04-02