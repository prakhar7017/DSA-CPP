class Solution {
public:
    string solveOptimised(string s, string t) {
        vector<int> freq(128, 0);
        for (char c : t)
            freq[c]++;

        int l = 0;
        int count = t.size();
        int start = 0;
        int minLen = INT_MAX;

        for (int r = 0; r < s.size(); r++) {
            if (freq[s[r]] > 0)
                count--;
            freq[s[r]]--;

            while (count == 0) {
                if (r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    start = l;
                }
                freq[s[l]]++;
                if (freq[s[l]] > 0)
                    count++;
                l++;
            }
        }
        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
    string minWindow(string s, string t) { return solveOptimised(s, t); }
};