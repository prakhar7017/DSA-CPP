class Solution {
public:
    bool isValid(int i, int j, int k, string s) {
        int maxF = 0;
        int arr[26] = {0};
        for (int k = i; k <= j; k++) {
            int idx = s[k] - 'A';
            arr[idx]++;
            maxF = max(maxF, arr[idx]);
        }
        return ((j - i + 1) - maxF <= k);
    }
    int bruteForce(string s, int k) {
        int n = s.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (isValid(i, j, k, s)) {
                    ans = max(ans, j - i + 1);
                }
            }
        }
        return ans;
    }
    int optimised(string s, int k) {
        int n = s.size();
        int ans = 0;
        int l = 0;
        int arr[26] = {0};
        int maxF = 0;
        for (int r = 0; r < n; r++) {
            arr[s[r] - 'A']++;
            maxF = max(maxF, arr[s[r] - 'A']);
            while ((r - l + 1) - maxF > k) {
                arr[s[l]-'A']--;
                l++;
            } // if invalid do soemthing

            ans = max(ans, r - l + 1);
        }
        return ans;
    }
    int characterReplacement(string s, int k) { return optimised(s, k); }
};