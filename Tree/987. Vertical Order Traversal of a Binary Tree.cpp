class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>ans;
        if(!root) return ans;
        queue<pair<TreeNode*,pair<int,int>>>q; // {node,{row,col}}
        q.push({root,{0,0}});

        map<int,map<int,multiset<int>>>mp; //map<col<row,multiset<int>>>

        while(!q.empty()){
            auto front=q.front();
            q.pop();

            TreeNode*& node=front.first;
            auto& cordinate=front.second;

            int& row=cordinate.first;
            int& col=cordinate.second;

            mp[col][row].insert(node->val);

            if(node->left){
                q.push({node->left,{row+1,col-1}});
            } 
            if(node->right){
                q.push({node->right,{row+1,col+1}});
            }
        }

        for(auto it:mp){
            auto& colMap=it.second;
            vector<int>vLine;
            for(auto colMapIt:colMap){
                auto& mset=colMapIt.second;
                vLine.insert(vLine.end(),mset.begin(),mset.end());
            }
            ans.push_back(vLine);
        }
        return ans;
    }
};