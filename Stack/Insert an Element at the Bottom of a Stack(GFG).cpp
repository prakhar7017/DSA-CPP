// Problem Statement: You are given a stack st of n integers and an element x. You have to insert x at the bottom of the given stack. 


class Solution{
public:
    void solve(stack<int>&st,int x){
        if(st.empty()){
            st.push(x);
            return ;
        } 
        
        int topElement=st.top();
        st.pop();
        
        solve(st,x);
        
        st.push(topElement);
    }
    stack<int> insertAtBottom(stack<int> st,int x){
        solve(st,x);
        return st;
    }
};

// time complexity o(n)
// space complexity o(n)