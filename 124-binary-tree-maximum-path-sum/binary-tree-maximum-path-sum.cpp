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
        if(root==nullptr) return 0;

        int leftAns = solve(root->left);
        int rightAns = solve(root->right);

        int neche_he_ans_milgya = leftAns+rightAns+root->val;
        int koi_ek_he_acha_hai = max(leftAns,rightAns) + root->val;
        int only_root_acha_hai = root->val;

        maxSum = max({maxSum,neche_he_ans_milgya,koi_ek_he_acha_hai,only_root_acha_hai});

        return max(koi_ek_he_acha_hai,only_root_acha_hai);
    }
    int maxPathSum(TreeNode* root) {
        maxSum = INT_MIN;
        solve(root);
        return maxSum;
    }
};