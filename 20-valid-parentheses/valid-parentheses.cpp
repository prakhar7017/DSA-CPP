class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        int n  = s.length();
        for(int i=0;i<n;i++){
            char ch = s[i];
            if(ch=='(') st.push(')');
            else if(ch == '{') st.push('}');
            else if(ch == '[') st.push(']');
            else if(st.empty() || st.top()!=ch) return false;
            else st.pop();
        }
        return st.empty();
    }
};