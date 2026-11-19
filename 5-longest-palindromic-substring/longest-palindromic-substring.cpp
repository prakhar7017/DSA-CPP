class Solution {
public:
    int n;
    int checkPalindrome(int i,int j,string&s){
        while(i>=0 && j<s.length() && s[i]==s[j]){
            i--;
            j++;
        }
        return j-i-1;
    }
    string longestPalindrome(string s) {
        n = s.length();
        int st =0;
        int ed =0;

        for(int i=0;i<n;i++){
            int oddLen  = checkPalindrome(i,i,s); 
            int evenLen = checkPalindrome(i,i+1,s);

            int len = max(oddLen,evenLen);
            if(len > (ed-st)){
                st = i-(len-1)/2;
                ed = i+(len)/2;
            }
        }
        return s.substr(st,ed-st+1);
    }
};