class Solution {
    private:
    bool solve(TreeNode* root, int &targetSum,int &sum){
        if(root==NULL){
            return false;
        }
        sum+=root->val;

        if(root->left==NULL && root->right==NULL){
            if(sum==targetSum){
                sum-=root->val;
                return true;
            }else{
                sum-=root->val;
                return false;
            }
        }

        bool leftAns=solve(root->left,targetSum,sum);
        bool rightAns=solve(root->right,targetSum,sum);

        sum-=root->val;
        return rightAns || leftAns;

    }
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum=0;
        bool ans;
        ans=solve(root,targetSum,sum);
        return ans;   
    }
};