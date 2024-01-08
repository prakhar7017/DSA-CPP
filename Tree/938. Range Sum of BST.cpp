class Solution {
    private:
    void solve(TreeNode*& root, int& low, int& high,int &ans){
        if(!root) return;

        //LNR
        //L
        if(root->val>low){
            solve(root->left,low,high,ans);
        }

        //N
        if(root->val>=low && root->val<=high){
            ans+=root->val;
        }

        //R
        if(root->val<high){
            solve(root->right,low,high,ans);
        }

    }
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        int ans=0;
        solve(root,low,high,ans);
        return ans;   
    }
};