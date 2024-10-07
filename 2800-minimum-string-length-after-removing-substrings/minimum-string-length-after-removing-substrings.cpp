class Solution {
public:
    int minLength(string s) {
        int n = s.length();
        int i = 0;
        while (true) {
            n = s.length();
            if (n == 0){
                break;
            }
            if (s[i] == 'A') {
                if (i + 1 < n && s[i + 1] == 'B') {
                    s.erase(i, 2);
                    i = 0;
                    continue;
                }
            }
            if (s[i] == 'C') {
                if (i + 1 < n && s[i + 1] == 'D') {
                    s.erase(i, 2);
                    i = 0;
                    continue;
                }
            }
            i++;
            if (i == n){
                break;
            }
        }
        return s.length();
    }
};