// Problem : Euler Circuit in an Undirected Graph

// Description : Eulerian Path is a path in a graph that visits every edge exactly once. Eulerian Circuit is an Eulerian Path that starts and ends on the same vertex. Given the number of vertices v and adjacency list adj denoting the graph. Find that there exists the Euler circuit or not. Return 1 if there exist  alteast one eulerian path else 0.

// if the degree of all the vertices is even then only the Euler circuit exists in the graph.
class Solution {
public:
	bool isEularCircuitExist(int V, vector<int>adj[]){
	     vector<int> degree(V, 0);
	    
	    for(int i = 0; i<V; i++) {
	        
	        degree[i] = adj[i].size(); // storing the degree of each vertex
	        
	    }
	    
	    for(int i = 0; i<V; i++) {
	        if(degree[i] % 2 != 0) { // if any vertex has odd degree then return false
	            return false;
	        }
	    }
	    
	    return true;
	}

};
