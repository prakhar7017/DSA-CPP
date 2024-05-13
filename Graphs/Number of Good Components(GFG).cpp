/*
    Number of Good Components

    Given an undirected graph with v vertices(numbered from 1 to v) and e edges. Find the number of good components in the graph.
    A component of the graph is good if and only if the component is fully connected.
    Note: A fully connected component is a subgraph of a given graph such that there's an edge between every pair of vertices in the component, the given graph can be a disconnected graph. 

*/

class Solution {
  public:
    int eCount=0;
    int vCount=0;
    unordered_map<int,bool>vis;
    
    void dfs(int i ,unordered_map<int,list<int>>&adjList){
        vis[i]=true;
        ++vCount;
        eCount+=adjList[i].size();
        for(auto nbr:adjList[i]){
            if(!vis[nbr]){
                dfs(nbr,adjList);
            }
        }
    }
    int findNumberOfGoodComponent(int e, int v, vector<vector<int>> &edges) {
        unordered_map<int,list<int>>adjList;
        for(auto edge:edges){
            int u=edge[0];
            int v=edge[1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        int ans=0;
        for(int i=1;i<=v;i++){
            if(!vis[i]){
                eCount=vCount=0;
                dfs(i,adjList);
                if(eCount==(vCount*(vCount-1))){
                    ++ans;
                }
            }
        }
        return ans;
    }
};

// Time Complexity: O(V+E)
// Space Complexity: O(V+E) + O(V) + O(V) = O(V+E)
