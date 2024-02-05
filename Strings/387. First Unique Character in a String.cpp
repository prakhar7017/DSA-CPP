class Solution {
public:
    int firstUniqChar(string s) {
        vector<int>freq(26);
        int n=s.length();
        for(int i=0;i<n;i++){
            char ch=s[i];
            freq[ch-'a']++;
        }

        for(int i=0;i<n;i++){
            char ch=s[i];
            if(freq[ch-'a']==1){
                return i;
            }
        }
        return -1;
    }
};