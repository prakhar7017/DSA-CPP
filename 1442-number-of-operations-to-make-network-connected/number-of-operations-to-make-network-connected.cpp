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
    void unionSet(int u,int v,vector<int>&parent,vector<int>&rank){
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
    int makeConnected(int n, vector<vector<int>>& connections) {
        parent.resize(n);
        rank.resize(n,0);
        for(int comp=0;comp<n;comp++){
            parent[comp]=comp;
        }

        int extraEdge=0;
        for(vector<int>conn:connections){
            int u=conn[0];
            int v=conn[1];
            u=findParent(u,parent);
            v=findParent(v,parent);

            if(u==v){ // same parent ie. both comp belong to same set
                ++extraEdge;
            }else{
                unionSet(u,v,parent,rank);
            }
        }

        int noOfConnectedComponents=0;
        for(int comp=0;comp<n;comp++){
            if(comp==parent[comp]){
                ++noOfConnectedComponents;
            }
        }

        int noOfCables=noOfConnectedComponents-1;

        return extraEdge>=noOfCables ? noOfCables : -1;
    }
};