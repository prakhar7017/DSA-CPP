class Solution
{
    private:
    void solve(Node* root,vector<int>& topview){
        map<int,int>hdtoNode;
        queue<pair<Node*,int>>q;
        // initial state maintain
        q.push(make_pair(root,0));
        
        while(!q.empty()){
            pair<Node*,int>temp=q.front();
            q.pop();
            Node* frontNode=temp.first;
            int hdistance=temp.second;
            
            if(hdtoNode.find(hdistance)==hdtoNode.end()){
                hdtoNode[hdistance]=frontNode->data;
            }
            
            // child take care
            if(frontNode->left!=NULL){
                q.push(make_pair(frontNode->left,hdistance-1));
            }
            if(frontNode->right!=NULL){
                q.push(make_pair(frontNode->right,hdistance+1));
            }
        }
        
        for(auto it:hdtoNode){
            topview.push_back(it.second);
        }
        
    }
    public:
    vector<int> topView(Node *root)
    {
        vector<int>tpv;
        solve(root,tpv);
        return tpv;
    }

};

// time complexity: O(n)