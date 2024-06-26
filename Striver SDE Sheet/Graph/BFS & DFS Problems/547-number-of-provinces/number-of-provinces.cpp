class Solution {
public:
    void dfs(int city,vector<bool>&vis,unordered_map<int,list<int>>&adjList){
        vis[city]=true;

        for(auto &nbr:adjList[city]){
            if(!vis[nbr]){
                dfs(nbr,vis,adjList);
            }
        }
    }
    void bfs(int city,vector<bool>&vis,unordered_map<int,list<int>>&adjList){
        queue<int>q;
        q.push(city);
        vis[city]=true;

        while(!q.empty()){
            int frontCity=q.front();
            q.pop();
            for(int &nbr:adjList[frontCity]){
                if(!vis[nbr]){
                    q.push(nbr);
                    vis[nbr]=true;
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        unordered_map<int,list<int>>adjList;
        vector<bool>vis(n,false);

        for( int i=0;i<n;i++ ){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1){
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }

        int provinces=0;
        for(int city=0;city<n;city++){
            if(!vis[city]){
                // dfs(city,vis,adjList);
                bfs(city,vis,adjList);
                provinces++;
            }
        }
        return provinces;
    }
};