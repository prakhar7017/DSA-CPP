
// first approach with use of distance varaible and map
// time complexity O(nlogn) and space complexity O(n)
// when going left, distance increases by 1
// when going right, distance remains same
void solve(Node* root,int& d, map<int, vector<int>>& mp) {
    if (!root) return;
    
    mp[d].push_back(root->data);
    
    solve(root->left, ++d, mp);
    --d;
    solve(root->right,d, mp);
}

vector<int> diagonal(Node *root) {
    vector<int> ans;
    map<int, vector<int>> mp;
    int d = 0;
    solve(root,d,mp);
    
    for (auto it : mp) {
        for (auto v : it.second) {
            ans.push_back(v);
        }
    }
    
    return ans;
}


// better solution 
vector<int> diagonal(Node *root)
{
    vector<int>ans;
    queue<Node* >q;
    if(!root) return ans;
    
    q.push(root);
    while(!q.empty()){
        Node* temp=q.front();
        q.pop();
        while(temp){
            ans.push_back(temp->data);
            if(temp->left){
                q.push(temp->left);
            }
            temp=temp->right;
        }
    }
    return ans;
}
