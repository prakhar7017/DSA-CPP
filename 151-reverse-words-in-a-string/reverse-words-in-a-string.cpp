class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string token ="";
        string ans="";
        while(getline(ss,token,' ')){
            if(token.empty()) continue;
            if(ans.empty()){
                ans =token;
            }else{
                ans=token+" "+ans;
            }
        }
        return ans;
    }
};