class Solution {
public:
    typedef pair<int,int>P;
    int count = 0;
    void dfs(int node,int parent,unordered_map<int,vector<P>>&adj){

        for(auto &[nbrNode,check]:adj[node]){
            if(nbrNode == parent) continue;
            if(check==1) count+=1;
            dfs(nbrNode,node,adj);
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        unordered_map<int,vector<P>>adj;

        for(vector<int>&conn:connections){
            int u = conn[0];
            int v = conn[1];
            adj[u].push_back({v,1});
            adj[v].push_back({u,0});
        }
        dfs(0,-1,adj);
        return count;
    }
};