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


//-------------------------------------------------------------------------------
class Solution {
public:
    void inOrder(TreeNode* root,vector<int>&temp){
        if(!root) return;
        inOrder(root->left,temp);
        temp.push_back(root->val);
        inOrder(root->right,temp);
    }
    int getMinimumDifference(TreeNode* root) {
        vector<int>temp;
        int minDiff=INT_MAX;
        inOrder(root,temp);
        for(int i=1;i<temp.size();i++){
            minDiff=min(minDiff,temp[i]-temp[i-1]);
        }
        return minDiff;
    }
};

time complexity: o(n)
space complexity : o(n);

// link : https://www.geeksforgeeks.org/problems/minimum-absolute-difference-in-bst-1665139652/1