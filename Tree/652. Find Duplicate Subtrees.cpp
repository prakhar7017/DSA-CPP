class Solution {
public:
    vector<TreeNode*> ans;
    unordered_map<string,int>mp;
    string solve(TreeNode* &root){
        if(!root) return "N";

        string curr=to_string(root->val);
        string l=solve(root->left);
        string r=solve(root->right);
        string s=curr+","+l+","+r;
        if(mp.find(s)!=mp.end()){
            if(mp[s]==1){
                ans.push_back(root);
            }
            mp[s]++;
        }else{
            mp[s]=1;
        }
        return s;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        solve(root);
        return ans;
    }
};

// time complexity : O(n)