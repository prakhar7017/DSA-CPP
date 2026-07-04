class Solution {
public:
    bool bruteForce(string& str) {
        string newStr = "";

        for (char ch : str) {
            if (isalnum(ch)) {
                newStr.push_back(tolower(ch));
            }
        }
        if (newStr.size() == 0)
            return true;

        int s = 0;
        int e = newStr.size() - 1;

        while (s < e) {
            if (newStr[s++] != newStr[e--]) {
                return false;
            }
        }
        return true;
    }
    bool optimised(string str){
        int n = str.size();
        int s = 0;
        int e = n-1;

        while(s<e){
            while(s<e && !isalnum(str[s])) s++;
            while(s<e && !isalnum(str[e])) e--;
            if(tolower(str[s])!=tolower(str[e])) return false;
            s++;e--;
        }
        return true;
    }
    bool isPalindrome(string str) { return optimised(str);}
};