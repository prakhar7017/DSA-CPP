class Solution {
public:
    vector<int>parent;
    vector<int>rank;
    int findParent(int u){
        if(u==parent[u]) return u;
        return  parent[u]=findParent(parent[u]);
    }

    void Union(int u,int v){
        u=findParent(u);
        v=findParent(v);

        if(u==v) return;
        if(rank[u]>rank[v]) parent[v]=u;
        else if(rank[u]<rank[v]) parent[u]=v;
        else {
            parent[v]=u;
            rank[u]++;
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        rank.resize(n,0);

        for(int i=0;i<n;i++) parent[i]=i;

        for(vector<int>&edge:edges){
            Union(edge[0],edge[1]);
        }

        unordered_map<int,int>mp;

        for(int i=0;i<n;i++){
            int p = findParent(i);
            mp[p]++;
        }

        long long result = 0;
        long long remaining = n;

        for(auto &it:mp){
            long long size = it.second;
            result+=size*(remaining-size);
            remaining-=size;
        }

        return result;

    }
};