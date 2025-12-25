class Solution {
public:
    typedef pair<int,int>P;
    int minScore(int n, vector<vector<int>>& roads) {
        unordered_map<int,vector<P>>adj;
        for(vector<int>&road:roads){
            int u = road[0];
            int v = road[1];
            int cost = road[2];
            adj[u].push_back({v,cost});
            adj[v].push_back({u,cost});
        }
        vector<int>vis(n+1,false);
        queue<int>q;
        q.push(1);
        vis[1]=true;
        int ans=INT_MAX;
        while(!q.empty()){
            int currNode = q.front();
            q.pop();
            for(auto &it: adj[currNode]){
                int nbrNode = it.first;
                int nbrCost = it.second;
                ans = min(ans,nbrCost);
                if(!vis[nbrNode]) {
                    vis[nbrNode]=true;
                    q.push(nbrNode);
                }
            }
        }
        return ans;
    }
};