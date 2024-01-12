class Solution{
  public:
    void solve(Node* root,unordered_map<int,bool>&mp,bool& ans){
        if(!root) return ;
        
        mp[root->data]=1;
        
        if(!root->left && !root->right){
            int xp1=root->data+1;
            int xm1=root->data-1==0 ? root->data :  root->data-1;
            if(mp.find(xp1)!=mp.end() && mp.find(xm1)!=mp.end()){
            ans=true;return;
            }
        }
        
        
        
        solve(root->left,mp,ans);
        solve(root->right,mp,ans);
    }
    bool isDeadEnd(Node *root)
    {
        unordered_map<int,bool>mp;
        bool ans;
        solve(root,mp,ans);
        return ans;
        
    }
};