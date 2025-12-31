class DSU {
public:
    vector<int> parent;
    vector<int> rank;
    int components;
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        iota(begin(parent), end(parent), 0);
        components = n;
    }
    int findParent(int u) {
        if (parent[u] == u)
            return u;
        return parent[u] = findParent(parent[u]);
    }
    void Union(int x, int y) {
        x = findParent(x);
        y = findParent(y);

        if (x == y)
            return;

        if (rank[x] < rank[y]) {
            parent[x] = y;
        } else if (rank[x] > rank[y]) {
            parent[y] = x;
        } else {
            parent[y] = x;
            rank[x]++;
        }
        components--;
    }

    bool isvalidMST() {
        return components == 1;
    }
};

class Solution {
public:
    int Kruskal(int n,vector<vector<int>>& edges, int skip_edge, int forced_edge) {
        int sum = 0;
        DSU dsu(n);
        if (forced_edge != -1) {
            int u = edges[forced_edge][0];
            int v = edges[forced_edge][1];
            int wt = edges[forced_edge][2];
            dsu.Union(u, v);
            sum += wt;
        }
        for (int i = 0; i < edges.size(); i++) {
            if (skip_edge == i)
                continue;
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];

            if (dsu.findParent(u) != dsu.findParent(v)) {
                dsu.Union(u, v);
                sum += wt;
            }
        }

        if(!dsu.isvalidMST()) return INT_MAX; 
        return sum;
    }
    vector<vector<int>>
    findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        for (int i = 0; i < edges.size(); i++) {
            edges[i].push_back(i);
        }
        auto lambda = [&](vector<int>& v1, vector<int>& v2) {
            return v1[2] < v2[2];
        };
        sort(begin(edges), end(edges), lambda);

        int min_mst = Kruskal(n,edges, -1, -1);
        cout<<min_mst;
        vector<int> critical, pseudo_critical;
        for (int iedge = 0; iedge < edges.size(); iedge++) {
            if (Kruskal(n,edges, iedge, -1) > min_mst) {
                critical.push_back(edges[iedge][3]);
            } else if (Kruskal(n,edges, -1, iedge) == min_mst) {
                pseudo_critical.push_back(edges[iedge][3]);
            }
        }

        return {critical, pseudo_critical};
    }
};