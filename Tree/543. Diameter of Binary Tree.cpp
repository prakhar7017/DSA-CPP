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