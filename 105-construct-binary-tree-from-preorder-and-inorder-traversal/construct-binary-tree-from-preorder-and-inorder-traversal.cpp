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
    int findIndex(int ele, vector<int>& inorder){
        for(int i=0;i<inorder.size();i++){
            if(inorder[i]==ele) return i;
        }
        return -1;
    }
    TreeNode* solve(int &preIndex, int inOrderStart, int inOrderEnd, int size, vector<int>& preorder, vector<int>& inorder) {
        if(preIndex>size || inOrderStart > inOrderEnd) return nullptr;

        int element = preorder[preIndex++];
        TreeNode* root=  new TreeNode(element);
        int position = findIndex(element, inorder);
        root->left = solve(preIndex,inOrderStart,position-1,size,preorder,inorder);
        root->right = solve(preIndex,position+1,inOrderEnd,size,preorder,inorder);
        return root;

    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preIndex = 0;
        return solve(preIndex, 0, inorder.size() - 1, preorder.size(), preorder,
                     inorder);
    }
};