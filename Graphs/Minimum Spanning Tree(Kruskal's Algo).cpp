class Solution
{
	public:
	void getMeEdges(int &V,vector<vector<int>> adj[],vector<vector<int>>&edges){
	    for(int u=0;u<V;u++){
	        for(auto edge:adj[u]){
	            int v=edge[0];
	            int w=edge[1];
	            edges.push_back({u,v,w});
	        }
	    }
	}
	int findParent(vector<int>&parent,int node){
	    if(parent[node]==node){
	        return node;
	    }
	    // recursion
	    return parent[node]=findParent(parent,parent[node]); // path compression
	}
	void unionSet(int u,int v ,vector<int>&parent,vector<int>&rank){
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
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<int>parent(V);
        vector<int>rank(V,0);
        
        // initial state
        for(int u=0;u<V;u++){
            parent[u]=u;
        }
        
        vector<vector<int>>edges;
        getMeEdges(V,adj,edges);
        auto lamda=[&edges](vector<int>&a,vector<int>&b){
            return a[2]<b[2];
        };
        sort(edges.begin(),edges.end(),lamda);
        int ans=0;
        for(auto edge:edges){
            int u=edge[0];
            int v=edge[1];
            int w=edge[2];
            
            u=findParent(parent,u);
            v=findParent(parent,v);
            
            if(u!=v){ // parent differnt hh , toh merge karna hh u and v ko
                // do union
                unionSet(u,v,parent,rank);
                ans+=w; // add up karte hu hi karlo wt add
            }
        }
        return ans;
    }
};

// time complexity: O(E*log(E)) where E is the number of edges
// Auxiliary Space: O(V + E), where V is the number of vertices and E is the number of edges in the graph.