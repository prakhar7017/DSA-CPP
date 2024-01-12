
// Approach 1: O(nlogn) time complexity  
class Solution {
public:
    TreeNode* solve(vector<int>& p, int s, int e) {
        if (s > e) {
            return NULL;
        }

        int mid = (s + e) / 2;
        TreeNode* root = new TreeNode(p[mid]);
        root->left = solve(p, s, mid - 1);
        root->right = solve(p, mid + 1, e);
        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        sort(preorder.begin(), preorder.end());
        int s = 0;
        int e = preorder.size() - 1;
        return solve(preorder, s, e);
    }
};


// Approach 2: O(n) time complexity
class Solution {
public:
    TreeNode* solve(vector<int>& p,int min,int max,int& index){
        if(index>=p.size()) return NULL;

        TreeNode* root=NULL;
        if(p[index]>min && p[index]<max){
            root=new TreeNode(p[index++]);
            root->left=solve(p,min,root->val,index);
            root->right=solve(p,root->val,max,index);
        } 
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int min=INT_MIN;
        int max=INT_MAX;
        int i=0;
        return solve(preorder,min,max,i);
    }
};