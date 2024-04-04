Sum of all substrings of a number

Given an integer s represented as a string, the task is to get the sum of all possible sub-strings of this string.
As the answer will be large, return answer modulo 109+7. 

Note: The number may have leading zeros.

class Solution {
public:
    int mod = 1e9 + 7;

    void solve(string &s, int index, long long prev, long long &ans) {
        if (index >= s.size()) return;

        int num = s[index] - '0';
        long long curr = (prev * 10LL) % mod + (num * (index + 1)) % mod;
        ans = (ans + curr) % mod;

        solve(s, index + 1, curr, ans);
    }

    long long sumSubstrings(string s) {
        long long prev = 0;
        long long ans = 0;
        solve(s, 0, prev, ans);
        return ans;
    }
};

// time complexity: O(n)
// space complexity: O(1)

