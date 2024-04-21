class Solution {
public:
    bool dfs(int src,int dest,unordered_map<int,bool>&vis,unordered_map<int,list<int>>&adjList){
        if(src==dest) return true;

        vis[src]=true;

        for(auto nbr:adjList[src]){
            if(!vis[nbr] && dfs(nbr,dest,vis,adjList)==true){
                return true;
            }
        }
        return false;
    }
    bool bfs(int src,int dest,unordered_map<int,bool>&vis,unordered_map<int,list<int>>&adjList){
        queue<int>q;
        // initial state
        q.push(src);
        while(!q.empty()){
            int frontNode=q.front();
            q.pop();
            if(frontNode==dest) return true;

            for(auto nbr:adjList[frontNode]){
                if(!vis[nbr]){
                    q.push(nbr);
                    vis[nbr]=true;
                }
            }
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int,list<int>>adjList;

        for(auto edge:edges){
            int u=edge[0];
            int v=edge[1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        unordered_map<int,bool>vis;
        bool ans=bfs(source,destination,vis,adjList);
        return ans;

       
    }
};