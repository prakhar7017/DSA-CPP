class Solution {
  public:
    int countNodes(struct Node* root){
        if(!root){
            return 0;
        }
        int left=countNodes(root->left);
        int right=countNodes(root->right);
        return left + right + 1;
    }
    bool isCBT(struct Node* root,int i,int &n){
        if(!root) return true;
        if(i>n) return false;
        return isCBT(root->left,2*i,n) && isCBT(root->right,2*i+1,n);
    }
    bool isMaxOrder(struct Node* root){
        if(!root) return true;
        int left=isMaxOrder(root->left);
        int right=isMaxOrder(root->right);
        bool ans=false;
        if(!root->left && !root->right){
            ans=true;
        }else if(root->left && !root->right){
            ans=root->data > root->left->data;
        }else{
            ans=root->data>root->left->data && root->data > root->right->data;
        }
        return ans && left && right;
    }
    bool isHeap(struct Node* tree) {
        int n=countNodes(tree);
        int index=1;
        if(isCBT(tree,index,n)){
            if(isMaxOrder(tree)){
                return true;
            }else{
                return false;
            }
        }
        return false;
    }
};