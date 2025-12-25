class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    int findParent(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findParent(parent[node]);
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
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++)
            parent[i] = i;

        for (vector<int>& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            Union(u,v);
        }
        unordered_map<int,int>compSize;

        for(int i=0;i<n;i++){
            compSize[findParent(i)]++;
        }
        long long ans=0;
        long long remaining = n;
        for(auto &it:compSize){
            int size = it.second;
            ans+=size*(remaining-size);
            remaining-=size;
        }
        return ans;
    }
};