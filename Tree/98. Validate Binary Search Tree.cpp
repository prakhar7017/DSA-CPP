class Solution {
public:
    bool solve(TreeNode* &root,long long int lb,long long int ub){
        //base case
        if(!root) return true;

        bool rootCheck=((root->val>lb) && (root->val<ub));
        bool leftCheck=solve(root->left,lb,root->val);
        bool rightCheck=solve(root->right,root->val,ub);

        if(rootCheck && leftCheck && rightCheck){
            return true;
        }else{
            return false;
        }
    }
    bool isValidBST(TreeNode* root) {
        long long int lb=-2147483667; // its an edge case here
        long long int ub=2147483667; // its an edge case here

        return solve(root,lb,ub);
    }
};