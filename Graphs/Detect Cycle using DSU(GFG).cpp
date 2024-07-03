class Solution
{
    public:
    vector<int>rank;
    vector<int>parent;
    int findParent(int node,vector<int>&parent){
        if(node==parent[node]){
            return node;
        }
        return parent[node]=findParent(parent[node],parent);
    }
    void unionSet(int u,int v,vector<int>&parent,vector<int>&rank){
        u=findParent(u,parent);
        v=findParent(v,parent);
        
        if(u==v){
            parent[v]=u;
            rank[u]++;
        }else if(rank[u]<rank[v]){
            parent[u]=v;
        }else { // rank[u]>rank[v]
            parent[v]=u;
        }
    }
	int detectCycle(int V, vector<int>adj[])
	{
	    parent.resize(V);
	    rank.resize(V,0);
	    
	    for(int i=0;i<V;i++){
	        parent[i]=i;
	    }
	    
	    for(int u=0;u<V;u++){
	        for(int &v:adj[u]){
	            if(u<v){
	                int parent_u=findParent(u,parent);
	                int parent_v=findParent(v,parent);
	                if(parent_u==parent_v){
	                    return 1;
	                }else{
	                    unionSet(u,v,parent,rank);
	                }
	            }
	        }
	    }
	    return 0;
	}
};

// time complexity : o(n)
// space complexity : o(n)