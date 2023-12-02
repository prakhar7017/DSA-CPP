class Solution {
    private:
    bool isopen(char ch){
        if(ch=='(' || ch=='{' || ch=='['){
            return true;
        }
        return false;
    }
    bool isMatching(stack<char>&st,char& ch){
        if(ch==')' && !st.empty() && st.top()=='('){
            return true;
        }else if (ch=='}' && !st.empty() && st.top()=='{'){
            return true;
        }else if(ch==']' && !st.empty() && st.top()=='['){
            return true;
        }else{
            return false;
        }
    }
public:
    bool isValid(string s) {
        stack<char>st;
        for(int i=0;i<s.length();i++){
            char ch=s[i];
            if(isopen(ch)){  //opening bracket
                st.push(ch);
            }else{ // closing bracket 
                if(!st.empty()){
                    if(isMatching(st,ch)){
                        st.pop();
                    }else{
                        return false;
                    }
                }else{
                    return false;
                }
            }
        }

        if(st.empty()){
            return true;
        }else{
            return false;
        }
    }
};

time complexity: O(N)