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
    bool isBalanced(TreeNode* root) {
        if(root==NULL){
            return true;
        }

        int leftHeight=height(root->left);
        int rightHeight=height(root->right);

        int diff=abs(leftHeight-rightHeight);

        bool currNode=diff<=1;

        bool leftAns=isBalanced(root->left);
        bool rightAns=isBalanced(root->right);

        if(currNode && leftAns && rightAns){
            return true;
        }else{
            return false;
        }

    }
};

// fast method
class Solution {
public:
    bool isbalanced=true;
    int height(TreeNode* root){
        if(root==NULL){
            return 0;
        }

        int leftHeight=height(root->left);
        int rightHeight=height(root->right);

        if(isbalanced && (abs(leftHeight-rightHeight)>1)){
            isbalanced=false;
        }

        int height=max(leftHeight,rightHeight)+1;

        return height;
    }
    bool isBalanced(TreeNode* root) {
        if(!root){
            return true;
        }
        int lh=height(root->left);
        int rh=height(root->right);
        if(isbalanced && (abs(lh-rh)>1)){
            isbalanced=false;
        }
        return isbalanced;
    }
};