// Brute Force
class Solution {
public:
    int maxDiff=-1;
    void maxDiff_Util_Helper(TreeNode* root,TreeNode* child){
        if(!root || !child) return ;

        maxDiff=max(maxDiff,abs(root->val-child->val));

        maxDiff_Util_Helper(root,child->left);
        maxDiff_Util_Helper(root,child->right);
    }
    void maxDiff_Helper(TreeNode*& root){
        if(!root) return ;
        maxDiff_Util_Helper(root,root->left);
        maxDiff_Util_Helper(root,root->right);
        maxDiff_Helper(root->left);
        maxDiff_Helper(root->right);

    }
    int maxAncestorDiff(TreeNode* root) {
        maxDiff_Helper(root);
        return maxDiff;
    }
};

// Optimized
class Solution {
public:
    int solve(TreeNode* root,int minV,int maxV){
        if(!root){
            return abs(minV-maxV);
        }
        minV=min(minV,root->val);
        maxV=max(maxV,root->val);

        int leftAns=solve(root->left,minV,maxV);
        int rightAns=solve(root->right,minV,maxV);

        return max(leftAns,rightAns);
    }
    int maxAncestorDiff(TreeNode* root) {
        int minV=INT_MAX;
        int maxV=INT_MIN;
        return solve(root,minV,maxV);
    }
};

