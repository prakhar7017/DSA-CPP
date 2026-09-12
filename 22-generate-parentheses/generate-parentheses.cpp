class Solution {
public:
    vector<string>ans;
    bool isValid(string &curr){
        int count = 0;
        for(char ch:curr){
            if(ch == '(') count++;
            else count--;
            if(count < 0) return false;
        }
        return count == 0;
    }
    void solve(string&curr,int n){
        if(curr.length()==2*n){
            if(isValid(curr)) ans.push_back(curr);
            return;
        }
        curr.push_back('(');
        solve(curr,n);
        //backstrack
        curr.pop_back();
        curr.push_back(')');
        solve(curr,n);
        curr.pop_back();
    }
    void solve2(string&curr,int n,int open,int close){
        if(curr.length()==2*n){
            ans.push_back(curr);
            return;
        }
        if(open<n){
            curr.push_back('(');
            solve2(curr,n,open+1,close);
            curr.pop_back(); 
        }

        if(close<open){
            curr.push_back(')');
            solve(curr,n);
            curr.pop_back();
        }    
    }
    vector<string> generateParenthesis(int n) {
        string curr="";
        int open = 0;
        int close = 0;
        solve2(curr,n,open,close);
        return ans;
    }
};