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
    bool isbalanced=true;
    int height(TreeNode* root){
        if(!root) return 0;


        int leftAns=height(root->left);
        int rightAns=height(root->right);

        if(isbalanced && abs(leftAns-rightAns)>1){
            isbalanced=false;
        }

        return max(leftAns,rightAns)+1;
    }
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        int lh=height(root->left);
        int rh=height(root->right);
        if(isbalanced && (abs(lh-rh)>1)) isbalanced=false;
        return isbalanced;

    }
};