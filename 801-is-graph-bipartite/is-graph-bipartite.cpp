class Solution {
public:
    bool dfs_Helper(int u,vector<int>&color,int currColor,unordered_map<int,vector<int>>&adj){
        color[u]=currColor;

        for(int &v:adj[u]){
            if(color[v]==color[u]) return false;
            if(color[v]==-1){
                int colorofv=1-currColor;
                if(dfs_Helper(v,color,colorofv,adj)==false) return false; 
            }
        }
        return true;
    }
    bool solveUsingDFS(vector<vector<int>>& graph){
        int V=graph.size();
        vector<int>color(V,-1);
        unordered_map<int,vector<int>>adj;
        for(int u=0;u<V;u++){
            for(int &v:graph[u]){
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
        }

        for(int u=0;u<V;u++){
            if(color[u]==-1){
                if(dfs_Helper(u,color,1,adj)==false) return false;
            }
        }

        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        return solveUsingDFS(graph);
    }
};