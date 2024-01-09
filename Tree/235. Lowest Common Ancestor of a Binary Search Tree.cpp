class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //base case
        if(!root){
            return NULL;
        }

        // 1 case p and q both exist in left subtree
        if(p->val<root->val && q->val<root->val){
            TreeNode* leftAns=lowestCommonAncestor(root->left,p,q);
            return leftAns;
        }
        // 2 case p and q exist in right subtree
        if(p->val>root->val && q->val>root->val){
            TreeNode* rightAns=lowestCommonAncestor(root->right,p,q);
            return rightAns;
        }
        // 3 case p exist in left and q exist in right
        if(p->val<root->val && q->val>root->val){
            return root;;
        }
        // 4 case q exist in left and p exist in right
        if(q->val<root->val && p->val>root->val){
            return root;;
        }

        return root;
    }
};

// time complexity : O(n)
