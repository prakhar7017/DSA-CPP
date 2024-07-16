class Solution {
public:
    TreeNode* LCA(TreeNode* root,int &p, int &q){
        if(!root) return nullptr;
        if(root->val==p) return root;
        if(root->val==q) return root;

        TreeNode* leftAns=LCA(root->left,p,q);
        TreeNode* rightAns=LCA(root->right,p,q);

        if(leftAns==NULL && rightAns==NULL){
            return nullptr;
        }else if(leftAns!=NULL && rightAns==NULL){
            return leftAns;
        }else if(leftAns==NULL && rightAns!=NULL){
            return rightAns;
        }
        return root;
    }
    bool findPath(TreeNode* root,int &target,string &path){
        if(!root) return false;

        if(root->val==target){
            return true;
        }
        // go left
        path.push_back('L');
        if(findPath(root->left,target,path)==true){
            return true;
        }
        path.pop_back();

        // go right
        path.push_back('R');
        if(findPath(root->right,target,path)==true){
            return true;
        }
        path.pop_back();
        return false;
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* lca=LCA(root,startValue,destValue);

        string lcaToSrc="";
        string lcatoDest="";

        findPath(lca,startValue,lcaToSrc);
        findPath(lca,destValue,lcatoDest);

        string ans="";
        for(int i=0;i<lcaToSrc.length();i++){
            ans.push_back('U');
        }

        ans+=lcatoDest;

        return ans;


    }
};