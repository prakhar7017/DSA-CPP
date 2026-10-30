class Solution {
public:
    int optimal(string& s) {
        int n = s.length();
        int open = 0;
        int close = 0;
        int result = 0;

        for (int i = 0; i < n; i++) {
            char ch = s[i];
            if (ch == '(')
                open++;
            else
                close++;

            if (open == close)
                result = max(result, open + close);
            else if (close > open)
                open = close = 0;
        }

        open = 0;
        close = 0;

        for (int i = n - 1; i >= 0; i--) {
            char ch = s[i];
            if (ch == '(')
                open++;
            else
                close++;

            if (open == close)
                result = max(result, open + close);
            else if (open > close)
                open = close = 0;
        }
        return result;
    }
    int usingStack(string& s) {
        int n = s.length();
        stack<int> st;
        st.push(-1);
        int maxLen = 0;
        for (int i = 0; i < n; i++) {
            char ch = s[i];

            if(ch=='(') st.push(i);
            else{
                st.pop();

                if(st.empty()){
                    //inlvaid case
                    st.push(i);
                }else{
                    //valid case
                    int len = i-st.top();
                    maxLen = max(len,maxLen);
                }
            }
        }
        return maxLen;
    }
    int longestValidParentheses(string s) { return usingStack(s);}
};