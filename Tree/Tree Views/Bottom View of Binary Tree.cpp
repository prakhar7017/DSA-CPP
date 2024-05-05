class Solution {
    private:
    void solve(Node* root,vector<int>&btmviw){
        map<int,int>hdtoNode;
        queue<pair<Node*,int>>q;
        q.push(make_pair(root,0));
        
        while(!q.empty()){
            pair<Node*,int>temp=q.front();
            q.pop();
            Node* frontNode=temp.first;
            int hdDistance=temp.second;
            
            hdtoNode[hdDistance]=frontNode->data;
            
            // child take care
            if(frontNode->left!=NULL){
                q.push(make_pair(frontNode->left,hdDistance-1));
            }
            if(frontNode->right!=NULL){
                q.push(make_pair(frontNode->right,hdDistance+1));
            }
        }
        
        for(auto it:hdtoNode){
            btmviw.push_back(it.second);
        }
    }
  public:
    vector <int> bottomView(Node *root) {
        vector<int>btm;
        solve(root,btm);
        return btm;
    }
};

