class Solution {
    private:
    void solve(TreeNode* root, int &targetSum,int &sum,vector<int>&output,vector<vector<int>>&ans){
        if(root==NULL){
            return;
        }

        sum+=root->val;
        output.push_back(root->val);

        if(root->left==NULL && root->right==NULL){
            if(sum==targetSum){
                ans.push_back(output);
                sum-=root->val;
                output.pop_back();
                return;
            }else{
                sum-=root->val;
                output.pop_back();
                return ;
            }
        }

        solve(root->left,targetSum,sum,output,ans);
        solve(root->right,targetSum,sum,output,ans);

        sum-=root->val;
        output.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>ans;
        vector<int>output;
        int sum=0;

        solve(root,targetSum,sum,output,ans);
        return ans;
    }
};