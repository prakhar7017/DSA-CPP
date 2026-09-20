class Solution {
public:
    void DFS(int u,vector<int>&vis,unordered_map<int,vector<int>>&adj){
        vis[u]=true;
        for(int &v:adj[u]){
            if(!vis[v]) DFS(v,vis,adj);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        unordered_map<int,vector<int>>adj;
        for(int i=0;i<isConnected.size();i++){
            for(int j=0;j<isConnected[0].size();j++){
                if(isConnected[i][j]==1){
                    adj[i].push_back(j);
                }
            }
        }

        vector<int>vis(isConnected.size(),0);
        int count=0;
        for(int i=0;i<isConnected.size();i++){
            if(!vis[i]){
                DFS(i,vis,adj);
                count++;
            }
        }
        return count;
    }
};