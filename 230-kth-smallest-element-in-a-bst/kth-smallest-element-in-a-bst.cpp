/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    void inorder(TreeNode* root, vector<int>& arr) {
        if (root == nullptr)
            return;
        // left
        inorder(root->left, arr);
        // Node
        arr.push_back(root->val);
        // right
        inorder(root->right, arr);
    }
    int solveUsingBruteForce(TreeNode* root, int k) {
        vector<int> arr;
        inorder(root, arr);
        return arr[k - 1];
    }
    int kthSmallest(TreeNode* root, int k) { return solveUsingBruteForce(root,k);}
};