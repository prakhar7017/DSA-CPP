class Solution
{
    public:
    void solve(Node* &root,int &d,map<int,vector<int>>&mp){
        if(root==NULL) return ;
        mp[d].push_back(root->data);
        // lefft call
        solve(root->left,++d,mp);
        // wapis arha hu left sa
        // backtrack
        --d;
        solve(root->right,d,mp);
    }
    vector <int> diagonalSum(Node* root) {
        map<int,vector<int>>mp;
        int d=0;
        solve(root,d,mp);
        vector<int>ans;
        for(auto it:mp){
            int sum=0;
            for(auto val:it.second){
                sum+=val;
            }
            ans.push_back(sum);
        }
        return ans;
    }
};

// time complexity O(n)
// space complexity O(n)

//------------------------------------------------------------------------------------
// without using map
class Solution
{
    public:
    vector <int> diagonalSum(Node* root) {
        vector<int>result;
        if(!root) return result;
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            int sum=0;
            while(size>0){
                Node* frontNode=q.front();
                q.pop();
                while(frontNode){
                    if(frontNode->left) q.push(frontNode->left);
                    sum+=frontNode->data;
                    frontNode=frontNode->right;
                }
                --size;
            }
            result.push_back(sum);
        }
        return result;
    }
};

// time complexity O(n)
// space complexity o(n);