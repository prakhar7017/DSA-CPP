
// Using DFS
class Solution
{
	public:
	void solve(int src,unordered_map<int,bool>&vis,stack<int>&st,vector<int> adj[]){
	    vis[src]=true;
	    for(auto nbr:adj[src]){
	        if(!vis[nbr]) solve(nbr,vis,st,adj);
	    }
	    st.push(src);
	}
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int>ans;
	    unordered_map<int,bool>vis;
	    stack<int>st;
	    for(int i=0;i<V;i++){
	        if(!vis[i]){
	            solve(i,vis,st,adj);
	        }
	    }
	    while(!st.empty()){
	        int top=st.top();
	        st.pop();
	        ans.push_back(top);
	    }
	    return ans;
	}
};


// Using BFS
class Solution
{
	public:
	vector<int>solve(int V, vector<int> adj[]){
	    queue<int>q;
	    unordered_map<int,int>inDegree;
	    vector<int>ans;
	    
	    // preparing indgree
	    for(int i=0;i<V;i++){
	        for(auto nbr:adj[i]){
	            inDegree[nbr]++;
	        }
	    }
	    
	    // push all zero indegree nodes
	    for(int node=0;node<V;node++){
	        if(inDegree[node]==0){
	            q.push(node);
	        }
	    }
	    
	    // BFS
	    while(!q.empty()){
	        int frontNode=q.front();
	        q.pop();
	         ans.push_back(frontNode);
	         
	         for(auto nbr:adj[frontNode]){
	             inDegree[nbr]--;
	             
	             // check for zero
	             if(inDegree[nbr]==0){
	                 q.push(nbr);
	             }
	         }
	    }
	    return ans;
	}
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int>ans=solve(V,adj);
	    return ans;
	}
};