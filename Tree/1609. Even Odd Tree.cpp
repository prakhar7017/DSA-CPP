
// using level order traversal
class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        if(!root) return false;
        queue<TreeNode*>q;
        q.push(root);
        bool evenLevel=1;
        while(!q.empty()){
            int n=q.size();
            int prev;
            if(evenLevel) prev=INT_MIN;
            else prev=INT_MAX;

            while(n--){
                TreeNode* front=q.front();
                q.pop();
                if(evenLevel && (front->val%2==0 || front->val<=prev)) return false;
                if(!evenLevel && (front->val%2!=0 ||  front->val>=prev)) return false;
                prev=front->val;
                if(front->left) q.push(front->left);
                if(front->right) q.push(front->right);
            } 
            evenLevel=!evenLevel;
        }
        return true;
    }
};

// time complexity O(n) 
//space complexity O(n)

// using DFS
class Solution {
public:
    vector<int>levelPrev;
    bool solve(TreeNode* root, int level){
        if(!root) return true;

        if(level % 2 == 0 && root->val % 2 == 0) return false;
        if(level%2!=0 && root->val %2 !=0) return false;

        if(level>=levelPrev.size()){
            levelPrev.resize(level+1);
        }

        if(levelPrev[level]!=0){ // there is a value which i saw in past
            if((level%2==0 && root->val<=levelPrev[level]) || (level%2!=0 && root->val>=levelPrev[level])) return false;
        }

        levelPrev[level]=root->val;
        return solve(root->left,level+1) && solve(root->right,level+1);
    }
    bool isEvenOddTree(TreeNode* root) {
        return solve(root,0);
    }
};

// time complexity O(n) if we neglect the time taken to resize the vector.
// resize takes O(n) time. so effectively time complexity is O(n^2)
// space complexity O(level of tree)