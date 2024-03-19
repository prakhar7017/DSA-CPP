


// to be reviewed
class Solution {
public:
    int findParent(vector<int>& parent, int node) {
        if (parent[node] == node) return node;
        return parent[node] = findParent(parent, parent[node]);
    }

    int unionSet(int u, int v, vector<int>& parent, vector<int>& rank) {
        u = findParent(parent, u);
        v = findParent(parent, v);
        int ans = rank[u] * rank[v];
        if (u == v) {
            return ans;
        }
        if (rank[u] < rank[v]) {
            parent[u] = v;
            rank[v]++;
        }
        else {
            parent[v] = u;
            rank[u]++;
        }
        return ans;
    }

    vector<int> maximumWeight(int n, vector<vector<int>>& edges, int q, vector<int>& queries) {
        vector<int> parent(n);
        vector<int> rank(n, 0);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        sort(edges.begin(), edges.end(), [](vector<int>& a, vector<int>& b) {
            return a[2] < b[2];
        });

        map<int, int> wtToPaths; // {weight, number of paths with weight <= weight}
        int initialPaths = 0;
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            u = findParent(parent, u);
            v = findParent(parent, v);
                int paths = unionSet(u, v, parent, rank);
                wtToPaths[wt] = initialPaths + paths;
                initialPaths = wtToPaths[wt];
        }

        vector<int> ans;
        for (int query : queries) {
            int maxWt = 0;
            for (auto& it : wtToPaths) {
                if (it.first <= query) {
                    maxWt = max(maxWt, it.second);
                }
                else {
                    break;
                }
            }
            ans.push_back(maxWt);
        }

        return ans;
    }
};
