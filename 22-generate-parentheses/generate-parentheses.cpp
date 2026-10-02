class Solution {
public:
    bool isValid(string s){
        int count=0;
        for(char ch:s){
            if(ch == '(') count++;
            else count--;
            if(count<0) return false;
        }
        return count == 0;
    }
    void solve(int n,string&curr,vector<string>&ans){
        if(curr.length()==2*n){
            if(isValid(curr)) ans.push_back(curr);
            return;
        }
        curr.push_back('(');
        solve(n,curr,ans);
        //backtrack
        curr.pop_back();
        curr.push_back(')');
        solve(n,curr,ans);
        curr.pop_back();
    }
    void solveOptimize(int open,int close,int n,string&curr,vector<string>&ans){
        if(curr.length() == 2*n){
            ans.push_back(curr);
            return;
        }
        if(open<n){
            curr.push_back('(');
            solveOptimize(open+1,close,n,curr,ans);
            curr.pop_back();
        }
        if(close<open){
            curr.push_back(')');
            solveOptimize(open,close+1,n,curr,ans);
            curr.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string curr = "";
        solveOptimize(0,0,n,curr,ans);
        return ans;
    }
};