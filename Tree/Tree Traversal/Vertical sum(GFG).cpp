/*
    Vertical sum

    Given a binary tree having n nodes, find the vertical sum of the nodes that are in the same vertical line. Return all sums through different vertical lines starting from the left-most vertical line to the right-most vertical line.

*/

class Solution{
  public:
    vector <int> verticalSum(Node *root) {
        vector<int>ans; // to store ans
        map<int,list<int>>mp; // {hdDistance,list of all nodes at same hd distance}
        queue<pair<Node*,int>>q; // {Node,its hd distance}
        
        q.push({root,0}); // base consditon
        
        while(!q.empty()){
            pair<Node*,int> qTop=q.front();
            q.pop();
            Node* frontNode=qTop.first;
            int hdDistance=qTop.second;
            
            mp[hdDistance].push_back(frontNode->data); // store the data of node at hd distance
            
            if(frontNode->left){
                q.push({frontNode->left,hdDistance-1});
            }
            if(frontNode->right){
                q.push({frontNode->right,hdDistance+1});
            }
        }
        
        for(auto it:mp){
            int sum=accumulate(begin(it.second),end(it.second),0);
            ans.push_back(sum);
        }
        return ans;
    }
};

// time complexity: O(n)
// space complexity: O(n)