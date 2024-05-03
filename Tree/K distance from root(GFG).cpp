/*
    K distance from root
    
    Given a binary tree having n nodes and an integer k. Print all nodes that are at distance k from the root (root is considered at distance 0 from itself). Nodes should be printed from left to right.

*/

class Solution
{
    public:
    vector<int> Kdistance(struct Node *root, int k)
    {
        vector<int>ans;
        if(k==0){
            ans.push_back(root->data);
            return ans;
        }
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            if(k==0){
                while(n!=0){
                    Node* frontNode=q.front();
                    q.pop();
                    ans.push_back(frontNode->data);
                    n--;
                }
                return ans;
            }
            while(n!=0){
                Node* frontNode=q.front();
                q.pop();
                if(frontNode->left){
                    q.push(frontNode->left);
                }
                if(frontNode->right){
                    q.push(frontNode->right);
                }
                n--;
            }
            k--;
        }
        return ans;
        
    }
};

// time complexity: o(n);
// space complexity: o(n);