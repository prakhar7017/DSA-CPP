class Solution {
public:
    int longestPalindrome(string s) {
        int n=s.length();
        unordered_map<char,int>mp;
        for(int i=0;i<n;i++){
            char ch=s[i];
            mp[ch]++;
        }
        int ans=0;
        bool oddFreq=false;
        for(auto it:mp){
            if((it.second & 1) == 0){
                ans+=it.second;
            }else{
                ans+=it.second-1;
                oddFreq=true;
            }
        }

        if(oddFreq==true) return ans+1;
        return ans;

    }
};