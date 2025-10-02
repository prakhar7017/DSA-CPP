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

     bool solveUsingStack(string& s){
        stack<char>st;

        for(char &ch:s){
            if(st.empty() || ch=='(' || ch=='{' || ch=='['){
                st.push(ch);
                continue;
            }

            if(ch==')'){
                if(st.top()=='(') st.pop();
                else return false;
            }else if(ch=='}'){
                if(st.top()=='{') st.pop();
                else return false;
            }else if(ch==']'){
                if(st.top()=='[') st.pop();
                else return false;
            }else{
                return false;
            }
        }
        return st.empty();
    }
    bool isValid(string s) {
        return solveUsingStack(s);
    }
};