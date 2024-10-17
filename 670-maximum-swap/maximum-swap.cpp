class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        string t = s;

        sort(s.rbegin(), s.rend());

        for (int i = 0; i < s.size(); i++) {
            if (s[i] != t[i]) {
                int index = -1;
                for (int j = i + 1; j < t.size(); j++) {
                    if (t[j] == s[i]) {
                        index = j;
                    }
                }
                swap(t[index], t[i]);
                break;
            }
        }

        return stoi(t);
    }
};