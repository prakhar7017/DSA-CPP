class Solution {
public:
    int checkPalindrom(int i,int j, string &s){
        while(i>=0 && j<s.length() && s[i]==s[j]){
            i--;
            j++;
        }
        return j-i-1;
    }
    string solveUsingExpand(string &s){
        int n = s.length();
        int start =0;
        int end =0;
        for(int i=0;i<n;i++){
            int oddAns = checkPalindrom(i,i,s);
            int evenAns = checkPalindrom(i,i+1,s);

            int len = max(oddAns,evenAns);
            if(len>(end-start)){
                start = i-(len-1)/2;
                end   = i+(len)/2;
            }
        }
        return s.substr(start,end-start+1);
    }
    string longestPalindrome(string s) {
        return solveUsingExpand(s);
    }
};