class Solution {
public:
    void morrisTraversal(TreeNode*& root,vector<int>&v){
        TreeNode* curr=root;
        while(curr){
            if(!curr->left){
                v.push_back(curr->val);
                curr=curr->right;
            }else{
                TreeNode* pred=curr->left;
                while(pred->right!=curr && pred->right){
                    pred=pred->right;
                }

                if(!pred->right){
                    pred->right=curr;
                    curr=curr->left;
                }else{
                    pred->right=NULL;
                    v.push_back(curr->val);
                    curr=curr->right;
                }

            }
        }
    }
    TreeNode* solve(vector<int>&v,int s,int e){
        if(s>e){
            return NULL;
        }
        int mid=s+(e-s)/2;
        TreeNode* root=new TreeNode(v[mid]);
        root->left=solve(v,s,mid-1);
        root->right=solve(v,mid+1,e);
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>v;
        morrisTraversal(root,v);
        int s=0;
        int e=v.size()-1;
        return solve(v,s,e);
    }
};