class Solution {
  public:
    int sum(Node* root){
        if(!root) return 0;
        
        if(!root->left && !root->right){
            int temp=root->data;
            root->data=0;
            return temp;
        }
        
        int leftSum=sum(root->left);
        int rightSum=sum(root->right);
        
        int temp=root->data;
        root->data=leftSum+rightSum;
        return root->data+temp;
    }
    void toSumTree(Node *node)
    {
        int ans=sum(node);
    }
};

// time complexity: O(n)
// space complexity: O(h)

