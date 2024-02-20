class Solution {
public:
    map<pair<int,int>,vector<TreeNode*>>dp;
    vector<TreeNode*> solve(int start ,int end){
        //base 
        if(start>end){
            return {NULL};
        }

        if(start==end){ // single Node
            return {new TreeNode(start)};
        }

        if(dp.find({start,end})!=dp.end()){
            return dp[{start,end}];
        }
        vector<TreeNode*>ans;
        // explore all possible solutions
        for(int i=start;i<=end;i++){
            vector<TreeNode*>leftVector=solve(start,i-1);
            vector<TreeNode*>rightVector=solve(i+1,end);

            // find all unique tress from both vectors
            for(int j=0;j<leftVector.size();j++){
                for(int k=0;k<rightVector.size();k++){
                    TreeNode*root=new TreeNode(i);
                    root->left=leftVector[j];
                    root->right=rightVector[k];
                    ans.push_back(root);
                }
            }
        }
        return dp[{start,end}]=ans;
    }
    vector<TreeNode*> generateTrees(int n) {
        if(n==0){
            return {};
        }
        int start=1;
        int end=n;
        return solve(start,end);
    }
};