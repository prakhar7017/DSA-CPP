class Solution {
public:
    bool isPalindrome(string str) {
        string newStr = "";

        for(char ch:str){
            if(isalnum(ch)){
                newStr.push_back(tolower(ch));
            }
        }
        if(newStr.size() == 0) return true;

        int s = 0;
        int e = newStr.size()-1;

        while(s<e){
            if(newStr[s++]!=newStr[e--]){
                return false;
            }
        }
        return true;
    }
};