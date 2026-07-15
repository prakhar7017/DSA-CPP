class MinStack {
public:
    typedef pair<int, int> P;
    stack<P> st;

    MinStack() {
        
    }
    
    void push(int value) {
        if (st.empty()) {
            st.push({value, value});
        } else {
            int currMin = st.top().second;
            int newMin = min(value, currMin);
            st.push({value, newMin});
        }
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */