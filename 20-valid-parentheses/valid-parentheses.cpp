class Solution {
public:
    bool solveUsingMoreCleanApproach(string& s){
        stack<char>st;

        for(char &ch:s){
            if(ch=='(') st.push(')');
            else if(ch=='{') st.push('}');
            else if(ch=='[') st.push(']');
            else if(st.empty() || st.top()!=ch) return false;
            else st.pop();
        }
        return st.empty();
    }
    bool isValid(string s) {
        return solveUsingMoreCleanApproach(s);
    }
};