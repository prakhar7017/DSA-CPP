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

//******************************Python Solution********************************
class Solution:
    def firstUniqChar(self, s: str) -> int:
        freq=[0]*26
        n=len(s)
        for i in range(n):
            ch=s[i]
            freq[ord(ch)-ord('a')]+=1
        
        for i in range(n):
            ch=s[i]
            if(freq[ord(ch)-ord('a')]==1):
                return i

        return -1
        
// Time Complexity: O(n)
// Space Complexity: O(1)