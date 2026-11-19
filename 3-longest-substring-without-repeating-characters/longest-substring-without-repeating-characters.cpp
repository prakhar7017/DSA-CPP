class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int maxLen = 0;
        int l=0;
        int r=0;
        vector<int>arr(256,-1);
        while(r<n){
            char ch = s[r];
            if(arr[ch]!=-1){
                if(arr[ch]>=l) l=arr[ch]+1;
            }
            int len = r-l+1;
            if(len>maxLen){
                maxLen = len;
            }
            arr[ch]=r;
            r++;
        }
        return maxLen;
    }
};