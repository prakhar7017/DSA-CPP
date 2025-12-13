class UnionFind {
public:
    vector<int> parent, rank;
    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int findParent(int x) {
        if (parent[x] == x)
            return x;
        return parent[x] = findParent(parent[x]);
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

};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        UnionFind uf(n);
        unordered_map<int,int>rowmp,colmp;  //key -> index
        for(int i=0;i<n;i++){
            int x = stones[i][0];
            int y = stones[i][1];

            if(rowmp.count(x)){
                uf.Union(i,rowmp[x]);
            }else {
                rowmp[x]=i;
            }

            if(colmp.count(y)){
                uf.Union(i,colmp[y]);
            }else{
                colmp[y]=i;
            }
        }

        int components =0;
        for(int i=0;i<n;i++){
            if(uf.parent[i]==i){
                components++;
            }
        }

        return n-components;
    }
};