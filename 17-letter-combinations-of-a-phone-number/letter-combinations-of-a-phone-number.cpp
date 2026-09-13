class Solution {
public:
    unordered_map<char,string>mp={
        {'2',"abc"},
        {'3',"def"},
        {'4',"ghi"},
        {'5',"jkl"},
        {'6',"mno"},
        {'7',"pqrs"},
        {'8',"tuv"},
        {'9',"wxyz"},
    };
    vector<string> ans;
    void solve(int idx,string &temp,string &digits){
        if(idx>=digits.length()){
            ans.push_back(temp);
            return;
        }
        char ch = digits[idx];
        string str = mp[ch];

        for(int i=0;i<str.length();i++){
            temp.push_back(str[i]);
            solve(idx+1,temp,digits);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if (digits.length() == 0) return {};
        string temp ="";
        solve(0,temp,digits);
        return ans;
    }
};