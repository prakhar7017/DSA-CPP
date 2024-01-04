class Solution {
    private:
    int height(TreeNode* root){
        if(root==NULL){
            return 0;
        }

        int leftHeight=height(root->left);
        int rightHeight=height(root->right);
        int height=max(leftHeight,rightHeight)+1;
        return height;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL){
            return 0;
        }

        int op1=diameterOfBinaryTree(root->left);
        int op2=diameterOfBinaryTree(root->right);
        int op3=height(root->left)+height(root->right);
        return max(op1,max(op2,op3));
    }
};

// fast method
class Solution {
public:
    int D=0;
    int height(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int lh=height(root->left);
        int rh=height(root->right);
        int currD=lh+rh;
        D=max(D,currD);
        return max(lh,rh)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root){
            return 0;
        }
        int ans=height(root);
        return D;
    }
};