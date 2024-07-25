class Solution {
public:
    TreeNode* maxValue(TreeNode* root){
        if(root==NULL) return NULL;
        TreeNode* temp=root;
        while(temp->right!=NULL){
            temp=temp->right;
        }
        return temp;
    }
    TreeNode* deleteFromBST(TreeNode* root, int &key){
        if(root==NULL) return root;
        if(root->val==key){
            // target found now delete
            // which type of node
            if(root->left==NULL && root->right==NULL){
                delete root;
                return NULL;
            }else if(root->left==NULL && root->right!=NULL){
                TreeNode* temp=root->right;
                delete root;
                return temp;
            }else if(root->left!=NULL && root->right==NULL){
                TreeNode* temp=root->left;
                delete root;
                return temp;
            }else{
                int mini=maxValue(root->left)->val;
                root->val=mini;
                root->left=deleteFromBST(root->left,mini);
                return root;
            }
        }else if(root->val<key){
            root->right=deleteFromBST(root->right,key);
        }else{
            root->left=deleteFromBST(root->left,key);
        }
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        return deleteFromBST(root,key);
    }
};