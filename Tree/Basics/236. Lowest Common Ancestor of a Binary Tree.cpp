class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // base case
        if(root==NULL){
            return NULL;
        }

        if(root==p){
            return p;
        }

        if(root==q){
            return q;
        }

        TreeNode* leftAns=lowestCommonAncestor(root->left,p,q);
        TreeNode* rightAns=lowestCommonAncestor(root->right,p,q);

        if(leftAns==NULL && rightAns==NULL){
            return NULL;
        }else if(leftAns!=NULL && rightAns==NULL){
            return leftAns;
        }else if (leftAns==NULL && rightAns!=NULL){
            return rightAns;
        }else{
            return root;
        }
    }
};

