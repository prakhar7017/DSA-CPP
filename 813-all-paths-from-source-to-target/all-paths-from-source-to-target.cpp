class Solution {
public:
    void dfs(int start, int end, vector<int>& currPath, vector<vector<int>>& ans,
        vector<vector<int>>& graph) {
            currPath.push_back(start);
            if(start == end) {
                ans.push_back(currPath);
            }else {
                for(int &v:graph[start]){
                    dfs(v,end,currPath,ans,graph);
                }
            }
            currPath.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        int start = 0;
        int end = n - 1;
        vector<vector<int>> ans;
        vector<int> currPath;
        dfs(start, end, currPath, ans, graph);
        return ans;
    }
};