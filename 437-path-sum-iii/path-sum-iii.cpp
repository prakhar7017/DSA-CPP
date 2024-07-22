class Solution {
public:
    typedef long long ll;
    ll ans=0;
    void findPath(TreeNode* root, ll targetSum){
        if(!root) return ;
        if(root->val==targetSum){
            ++ans;
        }
        findPath(root->left,targetSum-root->val);
        findPath(root->right,targetSum-root->val);
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(root){
            findPath(root,targetSum);
            pathSum(root->left,targetSum);
            pathSum(root->right,targetSum);
        }
        return ans;
    }
};