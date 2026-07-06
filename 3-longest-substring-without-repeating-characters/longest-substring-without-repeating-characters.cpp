class Solution {
public:
    bool checkDuplicate(int i, int j, string& s) {
        vector<int> freq(256, 0);

        for (int k = i; k <= j; k++) {
            unsigned char c = s[k];
            if (freq[c])
                return false;
            freq[c] = 1;
        }
        return true;
    }
    int solveBruteForce(string s) {
        int maxLen = 0;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            char ch = s[i];
            for (int j = i; j < n; j++) {
                if (checkDuplicate(i, j, s)) {
                    maxLen = max(maxLen, j - i + 1);
                }
            }
        }
        return maxLen;
    }
    int optimised(string& s) {
        int n = s.size();
        int l = 0;
        int ans = 0;
        unordered_map<char, int> mp;
        for (int r = 0; r < n; r++) {
            char ch = s[r];
            if(mp.find(ch)!=mp.end() && mp[ch]>=l){
                l=mp[ch]+1;
            }
            mp[ch]=r;
            ans = max(ans,r-l+1);
        }
        return ans;
    }
    int lengthOfLongestSubstring(string s) { return optimised(s); }
};