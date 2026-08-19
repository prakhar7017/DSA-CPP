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
    bool _isBalanced=true;
    int height(TreeNode* root){
        if(!root) return 0;
        int leftAns = height(root->left);
        int rightAns = height(root->right);

        if(_isBalanced && abs(leftAns-rightAns)>1) _isBalanced = false;
        return max(leftAns,rightAns)+1;
    }

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
    bool isBalanced(TreeNode* root) { 
        // return checkBalance(root).first;
        if(!root) return true;
        int leftAns = height(root->left);
        int rightAns = height(root->right);

        if(_isBalanced && abs(leftAns-rightAns)>1) _isBalanced = false;
        return _isBalanced;
    }
};