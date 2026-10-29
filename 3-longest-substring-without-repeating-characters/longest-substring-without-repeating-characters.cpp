class Solution {
public:
    int solveUsingSlidingWindow(string& s) {
        //"abcabcbb"
        int n = s.length();
        int maxLen = 0;
        int l = 0;
        int r = 0;
        int startIndex = 0;
        vector<int> arr(256, -1); // arr[i] = i last seen on which index
        while (r < n) {
            char ch = s[r];
            if (arr[ch] != -1) {
                if (arr[ch] >= l)
                    l = arr[ch] + 1;
            }
            int len = r - l + 1;
            if (len > maxLen) {
                maxLen = len;
                startIndex = l;
            }
            arr[ch] = r;
            r++;
        }
        return maxLen;
    }
    int lengthOfLongestSubstring(string s) {return solveUsingSlidingWindow(s);}
};