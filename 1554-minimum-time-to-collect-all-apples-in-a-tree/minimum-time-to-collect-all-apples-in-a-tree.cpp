class Solution {
public:
    int DFS(int currNode, int parent,vector<bool>& hasApple,unordered_map<int,vector<int>>&adj){
        int time = 0 ;

        for(int &child:adj[currNode]){
            if(child == parent) continue;
            int time_from_child = DFS(child,currNode,hasApple,adj);

            if(time_from_child>0 || hasApple[child]){
                time+=time_from_child+2;
            }
        }
        return time;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        unordered_map<int,vector<int>>adj;

        for(vector<int>&edge:edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return DFS(0,-1,hasApple,adj);
    }
};