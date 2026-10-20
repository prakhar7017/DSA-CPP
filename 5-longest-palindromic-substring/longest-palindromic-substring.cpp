class Solution {
public:
    bool isPalindrome(int i,int j,string&s){
        while(i<=j){
            if(s[i]!=s[j]) return false;
            else {
                i++;
                j--;
            }
        }
        return true;
    }
    string longestPalindrome(string s) {
        int n = s.length();
        int startIndex = 0;
        int maxLen = INT_MIN;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(isPalindrome(i,j,s)){
                    if(j-i+1>maxLen){
                        startIndex = i;
                        maxLen = j-i+1;
                    }
                }
            }
        }
        return s.substr(startIndex,maxLen);
    }
};