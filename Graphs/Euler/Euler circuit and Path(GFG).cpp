// Problem Statement: Euler circuit and Path

// Description : An Eulerian Path is a path in graph that visits every edge exactly once. An Eulerian Circuit is an Eulerian Path which starts and ends on the same vertex. Given an undirected graph with V nodes, and E edges, with adjacency list adj, return 2 if the graph contains an eulerian circuit, else if the graph contains an eulerian path, return 1, otherwise, return 0.


class Solution {
public:
    void dfs(int src,vector<int>&visited,vector<int>adj[]){
        visited[src]=true;
        for(auto it=adj[src].begin(); it!=adj[src].end();it++){
            if(!visited[*it]){
                dfs(*it,visited,adj);
            }
        }
    }
    bool isConnected(int v,vector<int>adj[]){
        int nonZeroDegreeNode=-1;
        for(int i=0;i<v;i++){
            if(adj[i].size()>0){
                nonZeroDegreeNode=i;
                break;
            }
        }
        
        vector<int>visited(v,false);
        dfs(nonZeroDegreeNode,visited,adj);
        
        for(int i=0;i<v;i++){
            if(visited[i]==false && adj[i].size()>0){
                return false;
            }
        }
        return true;
    }
	int isEulerCircuit(int V, vector<int>adj[]){
	    //Check if all non-zero degree vertices are connected
	    if(isConnected(V,adj)==false)
	        return 0; //Non-Eulerian
	        
	   //Count vertices with odd degree     
	   int oddDegreeNodes=0;
	   for(int i=0;i<V;i++){
	       if((adj[i].size()&1)==1){
	           ++oddDegreeNodes;
	       }
	   }
	   // If count is more than 2, then graph is not Eulerian
        if (oddDegreeNodes > 2)
            return 0; //Non-Eulerian
        
        if(oddDegreeNodes == 2) {
            return 1; //Semi-Eulerian (It has only Euler Path)
        }
        
        return 2; //(Euler Circuit)
	}
};

// time complexity : O(V+E)
// space complexity : O(V)