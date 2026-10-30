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
    // void inorder(TreeNode* root, vector<int>& arr) {
    //     if (root == nullptr)
    //         return;
    //     // left
    //     inorder(root->left, arr);
    //     // Node
    //     arr.push_back(root->val);
    //     // right
    //     inorder(root->right, arr);
    // }
    // int solveUsingBruteForce(TreeNode* root, int k) {
    //     vector<int> arr;
    //     inorder(root, arr);
    //     return arr[k - 1];
    // }

    TreeNode* ans = nullptr;
    void inorder(TreeNode* root, int& i, int& k) {
        if (root == nullptr)
            return;
        // left
        inorder(root->left,i,k);
        // Node
        i++;
        if (i == k) {
            ans = root;
            return;
        }
        // right
        inorder(root->right,i,k);
    }
    int solveUsingWithoutArr(TreeNode* root, int k) {
        int i =0;
        inorder(root,i,k);
        return ans->val;
    }
    int solveUsingMorrisTraversal(TreeNode* root,int k){
        if(root==nullptr) return 0;
        TreeNode* curr = root;
        int i=0;
        int ans=0;
        while(curr!=nullptr){
            if(curr->left == nullptr){
                // arr.push_back(curr->val);
                i++;
                if(i==k) {
                    ans = curr->val;
                    break;
                }
                curr = curr->right;
            }else{
                TreeNode* leftChild = curr->left;
                while(leftChild->right!=nullptr){
                    leftChild = leftChild->right;
                }
                leftChild->right = curr;
                TreeNode* temp = curr;
                curr = curr->left;
                temp->left = nullptr;
            }
        }
        return ans;
    }
    int kthSmallest(TreeNode* root, int k) {
        return solveUsingMorrisTraversal(root, k);
    }
};