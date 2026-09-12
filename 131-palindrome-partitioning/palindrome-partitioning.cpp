class Solution {
public:
    vector<vector<string>> ans;
    bool isPalindrome(int idx,int i,string&s){
        int l =idx;
        int r =i;
        while(l<r){
            if(s[l]!=s[r]) return false;
            l++;
            r--;
        }
        return true;
    }
    void solve(int idx,vector<string>&curr,string&s){
        if(idx==s.length()) {
            ans.push_back(curr);
            return;
        }
        for(int i=idx;i<s.length();i++){
            if(isPalindrome(idx,i,s)){
                curr.push_back(s.substr(idx,i-idx+1));
                solve(i+1,curr,s);
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string>curr;
        solve(0,curr,s);
        return ans;
    }
};