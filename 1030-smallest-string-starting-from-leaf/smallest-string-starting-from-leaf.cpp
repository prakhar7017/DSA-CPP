class Solution {
public:
    string ans;
    void dfs(TreeNode* root,string curr){
        // base case
        if(!root) return ;

        curr=char(root->val+'a')+curr;

        //leaf node check
        if(!root->left && !root->right) {
            if(ans=="" || ans>curr) {
                ans=curr;
            }
            return;
        }

        dfs(root->left,curr);
        dfs(root->right,curr);
    }
    string smallestFromLeaf(TreeNode* root) {
        string curr="";
        dfs(root,curr);
        return ans;
    }
};