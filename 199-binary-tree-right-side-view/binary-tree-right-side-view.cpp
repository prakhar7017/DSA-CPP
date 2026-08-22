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
    void inorder(TreeNode* root,int height,map<int,TreeNode*>&mp){
        if(!root) return;
        mp[height]=root;
        inorder(root->left,height+1,mp);
        inorder(root->right,height+1,mp);
    }
    vector<int> solveUsingMap(TreeNode* root){
        if(!root) return {};
        map<int,TreeNode*>mp;
        vector<int>ans;
        inorder(root,0,mp);
        for(auto it:mp){
            ans.push_back(it.second->val);
        }
        return ans;
    }
    vector<int> solveUsingLevelOrder(TreeNode* root){
        if(!root) return {};
        queue<TreeNode*>q;
        q.push(root);
        vector<int>ans;
        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;i++){
                TreeNode* curr = q.front();
                q.pop();
                if(i==size-1) ans.push_back(curr->val);
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
        }
        return ans;
    }
    vector<int> rightSideView(TreeNode* root) {
        return solveUsingMap(root);
    }
};