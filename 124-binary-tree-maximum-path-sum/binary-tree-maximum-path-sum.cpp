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
    int maxSum;
    int solve(TreeNode* root){
        if(!root) return 0;
        int leftAns = solve(root->left);
        int rightAns = solve(root->right);

        int necche_he_ans = leftAns+rightAns + root->val;
        int koi_ek_acha = max(leftAns,rightAns)+root->val;
        int only_root = root->val;
        maxSum = max({maxSum,necche_he_ans,koi_ek_acha,only_root});
        return max(only_root,koi_ek_acha);
    }
    int maxPathSum(TreeNode* root) {
        maxSum = INT_MIN;
        solve(root);
        return maxSum;
    }
};