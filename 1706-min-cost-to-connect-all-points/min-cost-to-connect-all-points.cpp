class Solution {
public:
    typedef pair<int, int> P;
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        unordered_map<int, vector<P>> adj;
        for (int i = 0; i < n; i++) {
            int x1 = points[i][0];
            int y1 = points[i][1];
            for (int j = i + 1; j < n; j++) {
                int x2 = points[j][0];
                int y2 = points[j][1];
                int dis = abs(x2 - x1) + abs(y2 - y1);
                adj[i].push_back({j, dis});
                adj[j].push_back({i, dis});
            }
        }

        priority_queue<P,vector<P>,greater<P>> q;
        q.push({0, 0});
        vector<int> inmst(n, false);
        int sum = 0;
        while (!q.empty()) {
            int curr = q.top().second;
            int wt = q.top().first;
            q.pop();
            if (inmst[curr])
                continue;
            sum += wt;
            inmst[curr] = true;
            for (auto [v, d] : adj[curr]) {
                if (!inmst[v]) {
                    q.push({d, v});
                }
            }
        }
        return sum;
    }
};