class Solution {
public:
    void dfs(int src,vector<int>&eularPath,unordered_map<int,vector<int>>&adj){
        while(!adj[src].empty()){
            int adjNode=adj[src].back();
            adj[src].pop_back();
            dfs(adjNode,eularPath,adj);
        }
        eularPath.push_back(src);
    }
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int,vector<int>>adj;
        unordered_map<int,int>indeg,outdeg;
        // prepare adjlist and indegree and outdegree
        for(vector<int>&pair:pairs){
            int u=pair[0];
            int v=pair[1];
            adj[u].push_back(v);
            indeg[v]++;
            outdeg[u]++;
        }

        // find startnode using outdeg[node]-indeg[node]=1;
        int startNode=pairs[0][0];
        for(auto &it:adj){
            int node=it.first;
            if(outdeg[node]-indeg[node]==1) {
                startNode=node;
                break;
            }
        }
        // dfs traversal
        vector<int>eularPath;
        dfs(startNode,eularPath,adj);

        reverse(begin(eularPath),end(eularPath));
        vector<vector<int>>ans;
        for(int i=0;i<eularPath.size()-1;i++){
            ans.push_back({eularPath[i],eularPath[i+1]});
        }
        return ans;
    }
};