class Solution {
public:
    typedef pair<int,int>P;
    int BFS(int n,int src,int dst,int k,unordered_map<int,vector<P>>&adj){
        vector<int>result(n,INT_MAX);
        queue<P>q;
        q.push({0,src});
        result[src]=0;
        int steps = 0;
        while(!q.empty() && steps<=k){
            int size = q.size();
            steps++;
            while(size--){
                int curr = q.front().second;
                int d    = q.front().first;
                q.pop();
                for(auto [v,wt]:adj[curr]){
                    if(d+wt<result[v]){
                        result[v]=d+wt;
                        q.push({d+wt,v});
                    }
                }
            }
        }
        return result[dst] ==  INT_MAX ? -1 : result[dst];
    }
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int,vector<P>>adj;
        for(auto &flight:flights){
            int u = flight[0];
            int v = flight[1];
            int wt = flight[2];
            adj[u].push_back({v,wt});
        }
        return BFS(n,src,dst,k,adj);
    }
};