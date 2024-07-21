/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    typedef pair<TreeNode*,pair<int,int>> P;
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        queue<P>q;
        map<int,map<int,multiset<int>>>mp;

        q.push({root,{0,0}});

        while(!q.empty()){
            P frontPair=q.front();
            q.pop();

            TreeNode* &node=frontPair.first;
            pair<int,int> cordinates=frontPair.second;

            int row=cordinates.first;
            int col=cordinates.second;

            mp[col][row].insert(node->val);

            if(node->left){
                q.push({node->left,{row+1,col-1}});
            }
            if(node->right){
                q.push({node->right,{row+1,col+1}});
            }
        }

        for(auto it:mp){
            auto &colMap=it.second;
            vector<int>vLine;
            for(auto colMapIt:colMap){
                auto &mset=colMapIt.second;
                vLine.insert(vLine.end(),mset.begin(),mset.end());
            }
            ans.push_back(vLine);
        }
        return ans;
    }
};