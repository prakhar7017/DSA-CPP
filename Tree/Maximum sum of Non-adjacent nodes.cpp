class Solution{
  public:
    //Function to return the maximum sum of non-adjacent nodes.
    pair<int,int>solve(Node* & root){
        // base case
        if(!root) return {0,0}; //{include,exclude}
        
        auto leftAns=solve(root->left);
        auto rightAns=solve(root->right);
        
        // current root operation
        
        //root include
        int a=root->data+leftAns.second+rightAns.second;
        
        // root exclude
        int b=max(leftAns.first,leftAns.second)+max(rightAns.first,rightAns.second);
        
        return {a,b};
    }
    int getMaxSum(Node *root) 
    {
        auto ans=solve(root);
        return max(ans.first,ans.second);
    }
};

// time complexity : O(n)
