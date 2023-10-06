class Solution {
    private:
    bool isPalindrome(string &s,int st,int e){
        while(st<e){
            if(s[st]!=s[e]){
                return false;
            }
            st++;
            e--;
        }
        return true;
    }
public:
    string longestPalindrome(string s) {
        string ans="";
        for(int i=0;i<s.length();i++){
            for(int j=i;j<s.length();j++){
                if(isPalindrome(s,i,j)){
                    string temp=s.substr(i,j-i+1);
                    ans=temp.length()>ans.length() ? temp : ans;
                }
            }
        }
        return ans;

    }
};

// time complexity: O(n^3)