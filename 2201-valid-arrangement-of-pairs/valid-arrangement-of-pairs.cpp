class Solution {
public:
    vector<int>path;
    void DFS(int start,unordered_map<int,vector<int>>&adj){
        while(!adj[start].empty()){
            int nextNode = *adj[start].begin();
            adj[start].erase(adj[start].begin());
            DFS(nextNode,adj);
        }
        path.push_back(start);
    }
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int,int>indegree,outdegree;
        unordered_map<int,vector<int>>adj;
        for(auto &pair:pairs){
            adj[pair[0]].push_back(pair[1]);
            indegree[pair[1]]++;
            outdegree[pair[0]]++;
        }

        // find start node
        int startNode = pairs[0][0];
        for(auto &it:adj){
            int node = it.first;
            if(outdegree[node]-indegree[node] == 1) startNode = node;
        }

        DFS(startNode,adj);

        reverse(begin(path),end(path));
        vector<vector<int>> ans;
        for(int i=0;i<path.size()-1;i++){
            ans.push_back({path[i],path[i+1]});
        }
        return ans;
    }
};