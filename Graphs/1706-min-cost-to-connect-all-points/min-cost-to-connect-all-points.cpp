class Solution {
public:
    typedef pair<int,int> P;
    int V;
    int primsAlgo(vector<vector<P>>& adj) {
        vector<bool> inMST(V, false);
        priority_queue<P, vector<P>, greater<P>> pq; // Min-heap priority queue
        pq.push({0, 0}); // {weight, node}
        int sum = 0;

        while (!pq.empty()) {
            P topPair = pq.top();
            pq.pop();
            int val = topPair.first;
            int node = topPair.second;

            if (inMST[node]) continue;

            inMST[node] = true;
            sum += val;

            for (auto& nbr : adj[node]) {
                int nbrVal = nbr.first;
                int nbrNode = nbr.second;
                if (!inMST[nbrNode]) {
                    pq.push({nbrVal, nbrNode});
                }
            }
        }

        return sum;
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        V = points.size();
        vector<vector<P>> adj(V);

        for (int u = 0; u < V; ++u) {
            for (int v = u + 1; v < V; ++v) {
                int x1 = points[u][0];
                int y1 = points[u][1];
                int x2 = points[v][0];
                int y2 = points[v][1];
                int val = abs(x2 - x1) + abs(y2 - y1);
                adj[u].push_back({val, v});
                adj[v].push_back({val, u});
            }
        }

        int ans = primsAlgo(adj);
        return ans;
    }
};