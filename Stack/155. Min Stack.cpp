class MinStack {
public:
    vector<pair<int,int>>st;

    MinStack() {

    }
    
    void push(int val) {
        if(st.empty()){
            pair<int,int>p;
            p.first=val;
            p.second=val;
            st.push_back(p);
        }else{
            pair<int,int>p;
            p.first=val;
            int puraniMinVal=st.back().second;
            p.second=min(val,puraniMinVal);
            st.push_back(p);
        }
    }
    
    void pop() {
        if(!st.empty()){
            st.pop_back();
        }
    }
    
    int top() {
        if(st.empty()){
            return NULL;
        }
        return st.back().first;
    }
    
    int getMin() {
        return st.back().second;   
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */