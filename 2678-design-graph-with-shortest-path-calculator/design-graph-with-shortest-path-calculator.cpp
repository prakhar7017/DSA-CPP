class Graph {
public:
    typedef pair<int, int> P;
    unordered_map<int, vector<P>> adj;
    int N;
    priority_queue<P, vector<P>, greater<P>> pq;
    Graph(int n, vector<vector<int>>& edges) {
        N = n;
        for (vector<int>& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int cost = edge[2];
            adj[u].push_back({v, cost});
        }
    }

    void addEdge(vector<int> edge) {
        int u = edge[0];
        int v = edge[1];
        int cost = edge[2];
        adj[u].push_back({v, cost});
    }

    int shortestPath(int node1, int node2) {
        vector<int>result(N,INT_MAX);
        result[node1]=0;
        pq.push({0,node1});

        while(!pq.empty()){
            int currDist = pq.top().first;
            int currNode = pq.top().second;
            pq.pop();

            for(auto next:adj[currNode]){
                int nextNode = next.first;
                int nextDist = next.second;
                if(currDist+nextDist<result[nextNode]){
                    result[nextNode]= currDist+nextDist;
                    pq.push({result[nextNode],nextNode});
                }
            }

        }

        return result[node2]==INT_MAX ? -1 : result[node2];
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */