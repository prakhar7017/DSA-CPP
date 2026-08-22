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
    int solve(TreeNode* root, int &k){
        if(!root) return -1;
        int leftAns = solve(root->left,k); // L
        if(leftAns!=-1) return leftAns;
        --k;
        if(k==0) return root->val;
        int rightAns = solve(root->right,k);
        return rightAns;
    }
    int kthSmallest(TreeNode* root, int k) {
        return solve(root,k);
    }
};