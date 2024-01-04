class Solution {
    bool isMirror(TreeNode* p,TreeNode* q){
        // base case
        if(!p && !q) return true;

        if(p && q) return (p->val==q->val) && isMirror(p->left,q->right) && isMirror(p->right,q->left);

        return false;
    }
public:
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;

        return isMirror(root->left,root->right);
    }
};

// time complexity: O(n)
