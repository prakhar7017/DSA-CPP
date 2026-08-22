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
    int solve(TreeNode* root,int &maxSoFar){
        if(!root) return 0;
        int count  = 0;
        if(maxSoFar<=root->val) count++;
        int newMaxSoFar = max(maxSoFar,root->val);
        count += solve(root->left,newMaxSoFar);
        count += solve(root->right,newMaxSoFar);
        return count;
    }
    int goodNodes(TreeNode* root) {
        return solve(root,root->val);
    }
};