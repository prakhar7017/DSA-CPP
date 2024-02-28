// using depth approach
class Solution {
public:
    int maxLevel=-1;
    void solve(TreeNode* root,int currLevel,int &ans){
        // base case
        if(!root) return ;
        if(currLevel>maxLevel){
            maxLevel=currLevel;
            ans=root->val;
        }
        solve(root->left,currLevel+1,ans);
        solve(root->right,currLevel+1,ans); 
    }
    int findBottomLeftValue(TreeNode* root) {
        int ans=0;
        solve(root,0,ans);
        return ans;
    }
};


// using Level order traversal
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        int ans=0;
        while(!q.empty()){
            int n=q.size();
                TreeNode* front=q.front();
                q.pop();
                ans=front->val;
                if(front->right){
                    q.push(front->right);
                }
                if(front->left){
                    q.push(front->left);
                }
        }
        return ans;
    }
};

// using Level order traversal
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        int ans=0;
        while(!q.empty()){
            int n=q.size();
            while(n--){
                TreeNode* front=q.front();
                q.pop();
                ans=front->val;
                if(front->right){
                    q.push(front->right);
                }
                if(front->left){
                    q.push(front->left);
                }
            }
        }
        return ans;
    }
};