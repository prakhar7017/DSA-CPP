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
    // bool inorder(TreeNode* root, int &k,unordered_map<int,bool>&mp){
    //     if(root==nullptr) return false;

    //     if(inorder(root->left,k,mp)) return true;
    //     if(mp.find(k-root->val)!=mp.end()){
    //         return true;
    //     }
    //     mp[root->val]=true;
    //     if(inorder(root->right,k,mp)) return true; 
    //     return false;
    // }
    // bool solveUsingBruteForce(TreeNode* root, int k){
    //     unordered_map<int,bool>mp;
    //     return inorder(root,k,mp);
    // }

    void inorder(TreeNode* root,vector<int>&arr){
        if(root==nullptr) return ;
        inorder(root->left,arr);
        arr.push_back(root->val);
        inorder(root->right,arr);
    }
    bool solveUsingTwoSum(TreeNode* root, int k){
        vector<int>arr;
        inorder(root,arr);
        int s=0;
        int e = arr.size()-1;
        while(s<e){
            int sum = arr[s]+arr[e];
            if(sum == k) return true;
            else if(sum<k)s++;
            else e--;
        }
        return false;
    }
    bool findTarget(TreeNode* root, int k) {
        return solveUsingTwoSum(root,k);
    }
};