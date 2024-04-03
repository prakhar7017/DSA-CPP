// Kth common ancestor in BST
// Given a BST with n (n>=2) nodes, find the kth common ancestor of nodes x and y in the given tree. Return -1 if kth ancestor does not exist.

// Nodes x and y will always be present in the input of a BST, and x != y.

class Solution
{
    public:
    void solve(Node* root,int &x,int &y,vector<int>&temp){
        if(!root) return ;
        if(root->data==x || root->data == y){
            temp.push_back(root->data);
            return;
        }
        // x and y both left
        if(x<root->data && y<root->data){
            temp.push_back(root->data);
            solve(root->left,x,y,temp);
        }
                // x and y both right
        if(x>root->data && y>root->data){
            temp.push_back(root->data);
            solve(root->right,x,y,temp);
        }
                // x left  and y right
        if(x<root->data && y>root->data){
            temp.push_back(root->data);
            return ;
        }
        if(y<root->data && x>root->data){
            temp.push_back(root->data);
            return;
        }
        return;
    }
    /*You are required to complete below function */
    int kthCommonAncestor(Node *root, int k,int x, int y)
    {
        vector<int>temp;
        solve(root,x,y,temp);
        int n=temp.size();
        if(n<k) return -1;
        return temp[n-k];
    }
};

// time complexity: O(n)
// space complexity: O(n)