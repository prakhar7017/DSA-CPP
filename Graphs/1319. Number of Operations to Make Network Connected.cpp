class Solution {
public:
    int findParent(vector<int>&parent,int node){
        if(parent[node]==node) return node;
        return parent[node]=findParent(parent,parent[node]);
    }
    void unionSet(int u,int v,vector<int>&parent,vector<int>&rank){
        u=findParent(parent,u);
        v=findParent(parent,v);

        if(rank[u]<rank[v]){
            parent[u]=v;
            rank[v]++;
        }else{
            parent[v]=u;
            rank[u]++;
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<int>parent(n);
        vector<int>rank(n,0);

        //make all the node as individual component
        for(int u=0;u<n;u++){
            parent[u]=u;
        }
        int extraEdges=0;
        for(auto conn:connections){
            int u=conn[0];
            int v=conn[1];

            u=findParent(parent,u);
            v=findParent(parent,v);

            if(u!=v){ // differnet representative , then unite them
                unionSet(u,v,parent,rank);
            }else{ // means same representative , already united, means extra edge mil gyi
                ++extraEdges;
            }
        }

        int noOfConnectedComponents=0;
        for(int node=0;node<n;node++){
            if(parent[node]==node) ++noOfConnectedComponents;
        }
        int noOfCables= noOfConnectedComponents - 1 ;
        return extraEdges >= noOfCables ? noOfCables : -1 ;
    }
};

// observation: if there are n diconnected components then we need n-1 cables to connect them all
//             if there are n-1 cables then we can connect all the components
//             if there are less than n-1 cables then we can't connect all the components
//             if there are more than n-1 cables then we can connect all the components and we will have extra cables

// time complexity: O(n)
// space complexity: O(n)