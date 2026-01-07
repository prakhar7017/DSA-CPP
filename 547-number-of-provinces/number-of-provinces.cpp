class Solution {
public:
    vector<int>parent;
    vector<int>rank;
    int components;

    int findParent(int x){
        if(parent[x]==x) return x;
        return parent[x]=findParent(parent[x]);
    }

    void Union(int x,int y){
        x = findParent(x);
        y = findParent(y);

        if(x==y) return;

        if(rank[x]<rank[y]){
            parent[x]=y;
        }else if(rank[x]>rank[y]){
            parent[y]=x;
        }else{
            parent[y]=x;
            rank[x]++;
        }
        components--;
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        components = n;

        parent.resize(n);
        rank.resize(n,0);

        iota(begin(parent),end(parent),0);

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1){
                    Union(i,j);
                }
            }
        }
        return components;
    }
};