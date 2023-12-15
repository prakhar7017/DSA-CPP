class Solution
{
    private:
    void reverseQueue(queue<int> &q){
        // base case
        if(q.empty()){
            return;
        }
        
        //processing 
        int element=q.front();
        q.pop();
        
        // recursive call
        reverseQueue(q);
        
        //processing
        q.push(element);
        
    }
    public:
    queue<int> rev(queue<int> q)
    {
        reverseQueue(q);
        return q;
    }
};

// time complexity:O(n)


// using stack 
// void reverseQueue(queue<int>&q){
//   stack<int>st;
//   while(!q.empty()){
//     int element=q.front();
//     q.pop();
//     st.push(element);
//   }
//   while(!st.empty()){
//     int element=st.top();
//     st.pop();
//     q.push(element);
//   }
// }