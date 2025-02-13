// https://www.geeksforgeeks.org/problems/find-a-pair-with-given-target-in-bst/1

class Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class BSTIterator{
    stack<Node*>st;
    bool reverse=true;
    public:
        BSTIterator(Node* root,bool isReverse): reverse(isReverse) {
            pushAll(root);
        }
        
        bool hasNext(){
            return !st.empty();
        }
        
        int next(){
            Node* current=st.top();
            st.pop();
            if(reverse){
                pushAll(current->left);
            }
            else{
                pushAll(current->right);
            }
            return current->data;
        }
    
    private:
        void pushAll(Node* root){
            while (root != NULL) {
                st.push(root);
                if (reverse) {
                    root = root->right;
                } else {
                    root = root->left;
                }
            }   
        }
};

class Solution {
  public:
    bool findTarget(Node *root, int target) {
        if(root==NULL){
            return false;
        }
        BSTIterator* l= new BSTIterator(root,false);
        BSTIterator* r=new BSTIterator(root,true);
        
        int s=l->next();
        int e=r->next();
        
        while(s<e){
            int sum=s+e;
            if(sum==target) return true;
            else if(sum<target){
                s=l->next();
            }else{
                e=r->next();
            }
        }
        return false;
        
        
    }
};

// Time Complexity= O(n)
// space complexity=o(H)
