class Solution {
public:
    void createInorder(TreeNode* &root,string& s){
        if(!root){
            return;
        }
        if(!root->left && !root->right){
            s+=to_string(root->val)+",";
            return;
        }

        createInorder(root->left,s);
        createInorder(root->right,s);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        string s1="";
        string s2="";
        createInorder(root1,s1);
        createInorder(root2,s2);

        return s1==s2;
    }
};

// time complexity: O(n)