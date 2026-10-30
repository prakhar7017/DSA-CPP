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
 struct BSTIterator {
    stack<TreeNode*>st;
    bool reverse;
    BSTIterator(TreeNode* root,bool _reverse){
        reverse = _reverse;
        pushAll(root);
    }

    void pushAll(TreeNode* root){
        while(root!=nullptr){
            st.push(root);
            if(reverse){
                root=root->right;
            }else{
                root=root->left;
            }
        }
    }

    TreeNode* next(){
        TreeNode* topNode = st.top();
        st.pop();
        if(reverse){
            pushAll(topNode->left);
        }else{
            pushAll(topNode->right);
        }
        return topNode;
    }
    
};
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

    // void inorder(TreeNode* root,vector<int>&arr){
    //     if(root==nullptr) return ;
    //     inorder(root->left,arr);
    //     arr.push_back(root->val);
    //     inorder(root->right,arr);
    // }
    // bool solveUsingTwoSum(TreeNode* root, int k){
    //     vector<int>arr;
    //     inorder(root,arr);
    //     int s=0;
    //     int e = arr.size()-1;
    //     while(s<e){
    //         int sum = arr[s]+arr[e];
    //         if(sum == k) return true;
    //         else if(sum<k)s++;
    //         else e--;
    //     }
    //     return false;
    // }

    bool solveUsingBSTIterator(TreeNode* root, int k){
        BSTIterator left(root, false);
        BSTIterator right(root,true);
        TreeNode* s = left.next();
        TreeNode* e = right.next();
        while(s!=e){
            int sum = s->val+e->val;
            if(sum == k) return true;
            else if(sum<k) s = left.next();
            else e = right.next();
        }
        return false;
    }
    bool findTarget(TreeNode* root, int k) {
        return solveUsingBSTIterator(root,k);
    }
};