class Solution
{
public:
    pair<int,int> solve(Node* &root){
        // base case
        if(!root){
            return {0,0};
        }
        
        // ek case
        auto leftAns=solve(root->left);
        auto rightAns=solve(root->right);
        
        int sum=root->data;
        if(leftAns.first==rightAns.first){
            sum+=leftAns.second > rightAns.second ? leftAns.second : rightAns.second;
        }else if(leftAns.first>rightAns.first){
            sum+=leftAns.second;
        }else{
            sum+=rightAns.second;
        }
        return {max(leftAns.first,rightAns.first)+1,sum};
    }
    int sumOfLongRootToLeafPath(Node *root)
    {
        auto ans=solve(root);
        return ans.second;
    }
};