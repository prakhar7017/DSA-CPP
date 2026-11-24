class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int>arr(26,0);
        for(int i=0;i<s.length();i++){
            int idx = s[i]-'a';
            arr[idx]++;
        };

        for(int i=0;i<t.length();i++){
            int idx = t[i]-'a';
            arr[idx]--;
        }

        for(int i=0;i<26;i++){
            if(arr[i]!=0) return false;
        }

        return true;
    }
};