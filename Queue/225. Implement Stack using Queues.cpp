// method 1 (using 2 queues) where push is O(n) and pop is O(1) and peek is O(1)
class MyStack {
public:
    queue<int>q1,q2;
    MyStack() {
        
    }
    
    void push(int x) {
        q2.push(x);
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
         while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }

    }
    
    int pop() {
        int pop=-1;
        if(!q1.empty()){
            pop=q1.front();
            q1.pop();
        }
        return pop;
    }
    
    int top() {
        int top=-1;
        if(!q1.empty()){
            top=q1.front();
        }
        return top;
    }
    
    bool empty() {
        return q1.empty();
    }
};

// method 2 (using 2 queues) where push is O(1) and pop is amortized O(1) and peek is O(1)

class MyStack {
public:
    queue<int>q;
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
        for(int i=0;i<q.size()-1;i++){
            int front=q.front();
            q.pop();
            q.push(front);
        }
    }
    
    int pop() {
        int top=q.front();
        q.pop();
        return top;

    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};
