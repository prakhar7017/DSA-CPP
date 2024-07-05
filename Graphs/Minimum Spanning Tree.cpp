class Solution
{
	public:
	int getMinValueNode(vector<int>&key,vector<int>&MST){
	    int index=-1;
	    int minValue=INT_MAX;
	    for(int i=0;i<key.size();i++){
	        int value=key[i];
	        if(MST[i]==false && value<minValue){
	            minValue=value;
	            index=i;
	        }
	    }
	    return index;
	}
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // prepare 3 DS
        // key Ds, contains value of each node 
        vector<int>key(V,INT_MAX);
        // keep track of included nodes in MST
        vector<int>MST(V,false);
        // final structure
        vector<int>parent(V,-1);
        
        // initail State
        key[0]=0;
        
        while(true){
            // step 1 , find node which has min value
            int u=getMinValueNode(key,MST);
            if(u==-1) break;
            
            //update MST
            MST[u]=true;
            
            // traverse all adj of u
            for(auto nbr:adj[u]){
                int v=nbr[0];
                int w=nbr[1];
                if(MST[v]==false && w<key[v]){
                    key[v]=w;
                    parent[v]=u;
                }
            }
        }
        
        int sum=0;
        for(int u=0;u<parent.size();u++){
            if(parent[u]==-1) continue;
            for(auto nbr:adj[u]){
                int v=nbr[0];
                int w=nbr[1];
                if(v==parent[u]) sum+=w;
            }
        }
        return sum;
    }
};

// time complexity: O(E*log(E)) where E is the number of edges
// Auxiliary Space: O(V^2) where V is the number of vertex

// prims alogrithm can be implemented using min heap to reduce time complexity to O(E*log(V)) 
// why it is used , it is used to find nodewhich has min value in O(1) time


// Minimum Spanning Tree using Min heap 
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    typedef pair<int,int> P;
    
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<bool>inmst(V,false);
        priority_queue<P,vector<P>,greater<P>>pq;
        
        pq.push({0,0});
        int sum=0;
        
        while(!pq.empty()){
            P topPair=pq.top();
            pq.pop();
            
            int wt=topPair.first;
            int node=topPair.second;
            
            if(inmst[node]==true) continue;
            
            sum+=wt;
            
            inmst[node]=true;
            
            for(vector<int>&nbr:adj[node]){
                int nbrNode=nbr[0];
                int nbrWt=nbr[1];
                
                if(inmst[nbrNode]==false){
                    pq.push({nbrWt,nbrNode});
                }
            }
        }
        return sum;
    }
};


// time complexity: O(E*log(V))
// Auxiliary Space: O(V) where V is the number of vertex