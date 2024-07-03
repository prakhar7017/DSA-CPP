class Solution {
public:
    vector<int>parent;
    vector<int>rank;
    int findParent(int u,vector<int>&parent){
        if(u==parent[u]){
            return u;
        }
        return parent[u]=findParent(parent[u],parent);
    }

    void unionSet(int u,int v,vector<int>&rank,vector<int>&parent){
        
        u=findParent(u,parent);
        v=findParent(v,parent);

        if(u==v){
            parent[v]=u;
            rank[u]++;
        }else if(rank[u]<rank[v]){
            parent[u]=v;
        }else{
            parent[v]=u;
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        // 1: write find and union
        // 2: form connected components
        // 3: count the size of each component
        // 4: calculate the ans -> formulae size*(n-size)
        // 5: n-size 
        parent.resize(n);
        rank.resize(n,0);

        for(int node=0;node<n;node++){
            parent[node]=node;
        }

        for(vector<int>&edge:edges){
            int u=edge[0];
            int v=edge[1];

            u=findParent(u,parent);
            v=findParent(v,parent);

            if(u!=v){
                unionSet(u,v,rank,parent);
            }
        }

        unordered_map<int,int>mp;

        for(int node=0;node<n;node++){
            int _parent=findParent(node,parent);
            mp[_parent]++;
        }

        long long result=0;
        long long remainingNode=n;

        for(auto &it:mp){
            int size=it.second;
            result+=size*(remainingNode-size);
            remainingNode-=size;
        }
        return result;
    }
};