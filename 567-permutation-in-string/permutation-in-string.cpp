class Solution {
public:
    int arr[26] = {0};
    bool isValid(int i, int j, string s1, string s2) {
        int arr1[26] = {0};
        for (int k = i; k <= j; k++) {
            arr1[s2[k] - 'a']++;
        }

        for (int i = 0; i < 26; i++) {
            if (arr[i] != arr1[i])
                return false;
        }
        return true;
    }
    bool solveBruteForce(string s1, string s2) {
        int n = s2.size();
        int m = s1.size();
        for (int i = 0; i < m; i++) {
            int idx = s1[i] - 'a';
            arr[idx]++;
        }

        for (int i = 0; i <= n - m; i++) {
            for (int j = i; j < n; j++) {
                if (isValid(i, j, s1, s2)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool optimised(string s1, string s2){
        int m = s1.size();
        int n = s2.size();

        if(m>n) return false;

        vector<int> freq1(26,0) , freq2(26,0);

        for(char c: s1){
            freq1[c-'a']++;
        }

        int left = 0;
        for(int right = 0;right < n; right++){
            freq2[s2[right]-'a']++;
            if(right - left + 1 > m){
                freq2[s2[left]-'a']--;
                left++;
            }
            if(right-left+1==m && freq1 == freq2) return true;
        }
        return false;
    }
    bool checkInclusion(string s1, string s2) { return optimised(s1, s2); }
};