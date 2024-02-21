class Solution {
public:
    int solve(TreeNode* root,unordered_map<TreeNode*,int>&dp){
        //base case
        if(!root){
            return 0;
        }

        if(dp.find(root)!=dp.end()){
            return dp[root];
        }

        int includeHouse=root->val;
        int excludeHouse=0;

        if(root->left){
            includeHouse+=solve(root->left->left,dp)+solve(root->left->right,dp);
        }
        if(root->right){
            includeHouse+=solve(root->right->left,dp)+solve(root->right->right,dp);
        }
        excludeHouse+=solve(root->left,dp)+solve(root->right,dp);

        return dp[root]=max(includeHouse,excludeHouse);

    }
    int rob(TreeNode* root) {
        unordered_map<TreeNode*,int>dp;
        return solve(root,dp);
    }
};

// time complexity: O(n)
// space complexity: O(n)