class DSU {
    public:
        vector<int>parent;
        vector<int>rank;
        int components;
        DSU(int n) {
            parent.resize(n+1);
            rank.resize(n+1,0);
            iota(begin(parent),end(parent),0);
            components = n;
        }

        int findParent(int x) {
            if(x==parent[x]) return x;
            return parent[x] = findParent(parent[x]);
        }

        void Union(int x, int y) {
            x = findParent(x);
            y = findParent(y);

            if(x==y) return;

            if(rank[x]<rank[y]){
                parent[x]=y;
            }else if(rank[x]>rank[y]){
                parent[y]=x;
            } else {
                parent[y]=x;
                rank[x]++;
            }
            components--;
        }

        bool isFullyConected() {
            return components == 1;
        }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        DSU Alice(n);
        DSU Bob(n);
        auto lambda = [&](vector<int> &v1, vector<int> &v2){
            return v1[0]>v2[0];
        };
        sort(begin(edges),end(edges),lambda);

        int edgesUsed = 0;
        for(vector<int> &edge:edges){
            int type = edge[0];
            int u = edge[1];
            int v = edge[2];

            if(type == 3) {
                bool isEdgeUsed = false;
                if(Alice.findParent(u)!=Alice.findParent(v)){
                    Alice.Union(u,v);
                    isEdgeUsed=true;
                }

                if(Bob.findParent(u)!=Bob.findParent(v)){
                    Bob.Union(u,v);
                    isEdgeUsed=true;
                }

                if(isEdgeUsed) edgesUsed++;
            } else if( type == 2) {
                if(Bob.findParent(u)!=Bob.findParent(v)){
                    Bob.Union(u,v);
                    edgesUsed++;
                }
            } else {
                if(Alice.findParent(u)!=Alice.findParent(v)){
                    Alice.Union(u,v);
                    edgesUsed++;
                }
            }
        }

        if(Alice.isFullyConected() && Bob.isFullyConected()) {
            return edges.size() - edgesUsed;
        }
        return -1;
    }
};