/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool solve(TreeNode* root,long long min,long long max){
        if(!root) return true;
        bool currAns = (root->val>min && root->val<max);
        if(!currAns) return false;
        bool leftAns = solve(root->left,min,root->val);
        bool rightAns = solve(root->right,root->val,max);
        return (leftAns && rightAns && currAns);
    }
    bool isValidBST(TreeNode* root) {
        long long min = LLONG_MIN;
        long long max = LLONG_MAX;
        return solve(root,min,max);
    }
};