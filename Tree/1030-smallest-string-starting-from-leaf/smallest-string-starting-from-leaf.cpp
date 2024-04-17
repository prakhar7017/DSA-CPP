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


// using BFS
class Solution {
public:
    string ans;
    string smallestFromLeaf(TreeNode* root) {
        queue<pair<TreeNode*,string>> q; // queue({node,curr})
        // initial State
        q.push({root,string(1,char(root->val+'a'))}); // push root node and its value in string form

        while(!q.empty()){
            auto[node,curr]=q.front(); // get the node and and curr string 
            q.pop();

            if(!node->left && !node->right) { // check if the current node is leaf node
                if(ans=="" || ans>curr){ // if ans is empty or ans is greater than curr
                    ans=curr; // update ans
                }
            }

            if(node->left){ // if left child is present
                q.push({node->left,char(node->left->val+'a')+curr}); // push left child and its value in string form
            }
            if(node->right){ // if right child is present
                q.push({node->right,char(node->right->val+'a')+curr}); // push right child and its value in string form
            }
        }
        return ans;
    }
};

// time complexity : O(n)
// space complexity : O(n)


//---------------------------------------------------------------------------------

// using DFS

class Solution {
public:
    string ans;
    void dfs(TreeNode* root,string curr){ 
        // base case
        if(!root) return ; // if root is null return

        curr=char(root->val+'a')+curr; // add the current node value to the curr string . and we are appending current node value to the left of the curr string because we need to find the string from leaf node to root node
    //     a
    //   /  \
    //  b    c  
    // then the "ba" we be curr 

        //leaf node check
        if(!root->left && !root->right) {
            if(ans=="" || ans>curr) {// if ans is empty or ans is greater than curr
                ans=curr;
            }
            return;
        }

        dfs(root->left,curr);// recursive call to left child
        dfs(root->right,curr);//recursive call to right child
    }
    string smallestFromLeaf(TreeNode* root) {
        string curr="";
        dfs(root,curr);
        return ans;
    }
};

// time complexity : O(n)
// space complexity : O(n)