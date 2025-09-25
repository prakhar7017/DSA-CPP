class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>lastSeen;
        int n=s.length();
        int l=0;
        int maxLen=0;

        for(int r=0;r<n;r++){
            char ch = s[r];
            if(lastSeen.find(ch)!=lastSeen.end() && lastSeen[ch]>=l){
                l = lastSeen[ch] + 1;
            }
            maxLen = max(r-l+1,maxLen);
            lastSeen[ch]=r;
        }
        return maxLen;
    }
};