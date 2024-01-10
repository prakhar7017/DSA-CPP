class Solution {
public:
    TreeNode* makeNodeToParentMappingAndFindTargetNode(TreeNode* root, unordered_map<TreeNode*,TreeNode*>&mp ,int start){
        if(!root){
            return NULL;
        }
        queue<TreeNode*>q;
        TreeNode* targetNode=NULL;
        q.push(root);
        while(!q.empty()){
            auto front=q.front(); q.pop();

            if(front->val==start) targetNode=front;
            if(front->left){
                mp[front->left]=front;
                q.push(front->left);
            }
            if(front->right){
                mp[front->right]=front;
                q.push(front->right);
            }
        }
        return targetNode;
    }

    int burnTheTree(TreeNode* targetNode,unordered_map<TreeNode*,TreeNode*>&mp){
        queue<TreeNode*>q;
        unordered_map<TreeNode*,bool>isBurnt;
        int time=0;
        q.push(targetNode);
        isBurnt[targetNode]=1;
        while(!q.empty()){
            int size=q.size();       
            bool isFireSpread=0;
            for(int i=0;i<size;i++){
                auto front=q.front(); q.pop();
                if(front->left && !isBurnt[front->left]){
                    q.push(front->left);
                    isBurnt[front->left]=1;
                    isFireSpread=1;
                }
                if(front->right && !isBurnt[front->right]){
                    q.push(front->right);
                    isBurnt[front->right]=1;
                    isFireSpread=1;
                }
                if(mp[front] && !isBurnt[mp[front]]){
                    q.push(mp[front]);
                    isBurnt[mp[front]]=1;
                    isFireSpread=1;
                }
            } 
            if(isFireSpread) time++;
        }
        return time;
    }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*,TreeNode*>mp;
        auto targetNode=makeNodeToParentMappingAndFindTargetNode(root,mp,start);
        return burnTheTree(targetNode,mp);
    }
};