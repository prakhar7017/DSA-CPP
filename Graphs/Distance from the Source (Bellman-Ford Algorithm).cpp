class Solution {
  public:
    /*  Function to implement Bellman Ford
    *   edges: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    #define INF 1e8
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        // initialState
        vector<int>dist(V,INF);
        dist[S]=0;
        
        // n-1 times relaxation
        for(int i=0;i<V;i++){
            for(vector<int>i:edges){
                int u=i[0];
                int v=i[1];
                int wt=i[2];
                if(dist[u]!=INF && dist[u]+wt < dist[v]){
                    dist[v]=dist[u]+wt;
                }
            }
        }
        
        // checking for negative cycle
        bool anyUpdate=false;
        for(vector<int>i:edges){
                int u=i[0];
                int v=i[1];
                int wt=i[2];
                if(dist[u]!=INF && dist[u]+wt < dist[v]){
                    anyUpdate=true; // negative cycle detected
                    break;
                    dist[v]=dist[u]+wt;
                }
            }
        if(anyUpdate) return {-1};
        return dist;
    }
};

// time complexity: O(n*m)
// space complexity: O(n)