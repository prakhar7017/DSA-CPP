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
    int solve(TreeNode* root,bool isLeft){
        // base case
        if(!root) return 0;

        if(!root->left && !root->right && isLeft==true){
            return root->val;
        }
        int leftAns=solve(root->left,true);
        int rightAns=solve(root->right,false);
        return leftAns+rightAns;
    }
    int sumOfLeftLeaves(TreeNode* root) {
        return solve(root,false);
    }
};

// time complexity : O(n)
// space complexity : O(1)

// link : https://leetcode.com/problems/sum-of-left-leaves/?envType=daily-question&envId=2024-04-14

