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
    typedef pair<bool,int>P;
    P checkBalance(TreeNode* root){
        if(!root) return {true,0};
        P leftAns = checkBalance(root->left);
        P rightAns = checkBalance(root->right);
        int height = max(leftAns.second, rightAns.second) + 1;
        if(leftAns.first && rightAns.first && (abs(leftAns.second-rightAns.second)<=1)){
            return {true,height};
        }
        return {false,height};
    }
    bool isBalanced(TreeNode* root) { return checkBalance(root).first;}
};