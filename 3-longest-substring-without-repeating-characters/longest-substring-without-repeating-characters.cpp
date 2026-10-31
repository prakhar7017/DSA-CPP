class Solution {
public:
    int solveUsingBruteForce(string& s) {
        //"abcabcbb"
        int n = s.length();
        int maxLen = 0;
        int startIndex = 0;
        for (int i = 0; i < n; i++) { // n
            vector<int> arr(256, 0);  // arr[i] freq will 1 if i is seen before
            for (int j = i; j < n; j++) { // n
                if (arr[s[j]] == 1)
                    break;
                if (j - i + 1 > maxLen) {
                    maxLen = j - i + 1;
                    startIndex = i;
                }
                arr[s[j]] = 1;
            }
        }
        return maxLen;
    }
    int solveUsingSlidingWindow(string& s) {
        //"abcabcbb"
        int n = s.length();
        int maxLen =0;
        int startIndex =0;
        int l=0;
        int r=0;
        vector<int>arr(256,-1);
        while(r<n){
            char ch = s[r];
            if(arr[ch]!=-1){
                if(arr[ch]>=l) l=arr[ch]+1;
            }
            int len = r-l+1;
            if(len > maxLen){
                maxLen = len;
                startIndex = l;
            }
            arr[ch]=r;
            r++;
        }
        return maxLen;
    }
    int lengthOfLongestSubstring(string s) {
        return solveUsingSlidingWindow(s);
    }
};