class Solution {
public:
    vector<int>parent;
    vector<int>rank;
    int find(int u){
        if(parent[u]==u) return u;
        return parent[u]=find(parent[u]);
    }

    void Union(int x,int y){
        x= find(x);
        y= find(y);

        if(x==y) return ;

        if(rank[x]<rank[y]){
            parent[x]=y;
        }else if(rank[x]>rank[y]){
            parent[y]=x;
        }else {
            parent[y]=x;
            rank[x]++;
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        int conn = connections.size();
        if(conn<n-1) return -1;
        int components=n;

        parent.resize(n);
        rank.resize(n);

        for(int i=0;i<n;i++){
            parent[i]=i;
            rank[i]=0;
        }

        for(vector<int>&edge:connections){
            int u = edge[0];
            int v = edge[1];

            if(find(u)==find(v)) continue;
            else {
                Union(u,v);
                components--;
            };
        }

        return components-1;
    }
};