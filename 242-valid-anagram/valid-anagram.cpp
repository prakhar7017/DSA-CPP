class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.size();
        int m = t.size();
        if(n!=m) return false;
        int arr[26]={0};
        for(int i=0;i<n;i++){
            int index = s[i]-'a';
            arr[index]++;
        }
        for(int i=0;i<m;i++){
            int index = t[i]-'a';
            arr[index]--;
        }

        for(int i=0;i<26;i++){
            if(arr[i]!=0) return false;
        }
        return true;
    }
};