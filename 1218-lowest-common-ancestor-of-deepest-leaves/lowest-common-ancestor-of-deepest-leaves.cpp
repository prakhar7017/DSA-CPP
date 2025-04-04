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
    typedef pair<int,TreeNode*>P; //{depth,node}
    unordered_map<int,int>mp;
    int maxD;
    void depth(TreeNode* root,int d){
        if(root==NULL){
            return;
        }
        mp[root->val]=d;
        maxD=max(maxD,d);
        depth(root->left,d+1);
        depth(root->right,d+1);
    }
    TreeNode* LCA(TreeNode* root){
        if(root==NULL || mp[root->val]==maxD){
            return root;
        }
        TreeNode* leftAns=LCA(root->left);
        TreeNode* rightAns=LCA(root->right);
        if(leftAns && rightAns) return root;
        // else if(!leftAns && rightAns) return rightAns;
        // else if(leftAns && !rightAns) return leftAns;
        // return nullptr;
        return leftAns!=NULL ? leftAns : rightAns;
    }
    P onePassSolve(TreeNode* root){
        if(root==NULL){
            return {0,NULL};
        }
        P leftAns=onePassSolve(root->left);
        P rightAns=onePassSolve(root->right);
        
        if(leftAns.first==rightAns.first){
            return {leftAns.first+1,root};
        }else if(leftAns.first > rightAns.first){
            return {leftAns.first+1,leftAns.second};
        }else {
            return {rightAns.first+1,rightAns.second};
        }
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        // depth(root,0);
        return onePassSolve(root).second;

    }
};