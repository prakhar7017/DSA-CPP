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
    bool checkSudoPalindrome(vector<int>&freq){
        int oddTimes=0;
        for(int i=0;i<10;i++){
            if(freq[i]%2!=0){
                oddTimes++;
            }
        }
        if(oddTimes<=1){
            return true;
        }else{
            return false;
        }
    }
    void solve(TreeNode* root,vector<int>&freq,int &ans){
        if(!root) return;
        int index=root->val;
        freq[index]++;
        if(!root->left && !root->right){
            if(checkSudoPalindrome(freq)){
                ans++;
            }
        }
        solve(root->left,freq,ans);
        solve(root->right,freq,ans);
        freq[index]--;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int>freq(10,0);
        int ans=0;
        solve(root,freq,ans);
        return ans;
    }
};

// plaindrome ki ek choti property hoti hh ki usmein ek hi odd frequency wala element ho skta hh
// agar ek sa zada element odd frequency mein hh toh wo palindrome nhi ho skta