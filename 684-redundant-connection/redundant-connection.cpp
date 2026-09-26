class Solution {
public:
    vector<int>parent;
    vector<int>rank;

    int findParent(int u){
        if(u == parent[u]) return u;
        return parent[u] = findParent(parent[u]);
    }
    void Union(int u,int v){
        u = findParent(u);
        v = findParent(v);

        if(u == v) return;

        if(rank[u]<rank[v]) parent[u]=v;
        else if(rank[u]>rank[v]) parent[v]=u;
        else {
            parent[v]=u;
            rank[u]++;
        }
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        parent.resize(n+1);
        rank.resize(n+1,1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }

        for(vector<int>&edge:edges){
            int u = edge[0];
            int v = edge[1];

            if(u<v){
                if(findParent(u) == findParent(v)) return edge;
                Union(u,v);
            }
        }
        return {};
    }
};