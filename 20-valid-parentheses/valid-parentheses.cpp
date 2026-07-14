class Solution {
public:
    bool solveBruteForce(string s){
        bool changed = true;
        while(changed){
            changed = false;
            for(int i=0;i+1<s.size();i++){
                if((s[i]=='(' && s[i+1]==')') || (s[i]=='{' && s[i+1]=='}') || (s[i]=='[' && s[i+1]==']')){
                    s.erase(i,2);
                    changed = true;
                    break; // restart scaning after modifying
                }
            }
        }
        return s.empty();
    }
    bool optimised(string s){
        stack<char>st;
        for(char ch:s){
            if(ch == '(') st.push(')');
            else if(ch == '{') st.push('}');
            else if(ch == '[') st.push(']');
            else if( st.empty() || st.top()!= ch) return false;
            else st.pop();
        }
        return st.empty();
    }
    bool isValid(string s) { return optimised(s); }
};