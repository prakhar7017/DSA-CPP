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
    void solve(TreeNode* root,int sum,int &finalSum){
        if(!root) return ;

        if(!root->left && !root->right){
            finalSum+=sum*10+root->val;
            return;
        }
        sum=sum*10+root->val;
        solve(root->left,sum,finalSum);
        solve(root->right,sum,finalSum);
        return;
    }
    int sumNumbers(TreeNode* root) {
        int finalSum=0;
        int sum=0;
        solve(root,sum,finalSum);
        return finalSum;

    }
};