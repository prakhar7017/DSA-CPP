class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        TreeNode* curr=root;

        while(curr){
            // visiting the node
            //LNR
            if(!curr->left){
                ans.push_back(curr->val);
                curr=curr->right;
            }else{
                // find inorder predecessor
                TreeNode* pred=curr->left;
                while(pred->right!=curr && pred->right){
                    pred=pred->right;
                }
                if(!pred->right){ // link establish karo
                    pred->right=curr;
                    curr=curr->left;
                }else{ // link already exist,then remove link 
                    pred->right=NULL;
                    ans.push_back(curr->val);
                    curr=curr->right;
                }
            }
        }
        return ans;
    }
};

