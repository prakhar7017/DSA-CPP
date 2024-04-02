Minimum Absolute Difference In BST

Given a binary search tree having n (n>1) nodes, the task is to find the minimum absolute difference between any two nodes. 

class Solution
{
    public:
    Node* prev=NULL;
    int minDiff=INT_MAX;
    void solve(Node* root){
        if(!root) return ;
        
        // left
        solve(root->left);
        
        // Node
        if(prev!=NULL){
            minDiff=min(minDiff,root->data-prev->data);
        }
        // right
        prev=root; // agar right hh toh uska prev kon hoga , root hoga isley right jane sa phle prev= root keya hh
        solve(root->right);
    }
    int absolute_diff(Node *root)
    {
        solve(root);
        return minDiff;
    }
};

// time complexity : o(n)
// space complexity :o(1)