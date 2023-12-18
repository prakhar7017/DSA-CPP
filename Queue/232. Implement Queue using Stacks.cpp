
// method 1 (using 2 stacks) where push is O(n) and pop is O(1) and peek is O(1)
class MyQueue {
public:
    stack<int>s1,s2;
    MyQueue() {
        
    }
    
    void push(int x) {
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
    }
    
    int pop() {
        int pop=-1;
        if(!s1.empty()){
            pop=s1.top();
            s1.pop();
        }
        return pop;
    }
    
    int peek() {
        int front=-1;
        if(!s1.empty()){
            front=s1.top();
        }
        return front;
    }
    
    bool empty() {
        return s1.empty();
    }
};

// method 2 (using 2 stacks) where push is O(1) and pop is amortized O(1) and peek is O(1)

class MyQueue {
public:
    stack<int>s1,s2;
    MyQueue() {
        
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        int pop=-1;
        if(!s2.empty()){
            pop=s2.top();
        }else{
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
            pop=s2.top();
        }
        s2.pop();
        return pop;
    }
    
    int peek() {
         int front=-1;
        if(!s2.empty()){
            front=s2.top();
        }else{
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
            front=s2.top();
        }
        return front;
    }
    
    bool empty() {
        return s1.empty() && s2.empty();
    }
};
