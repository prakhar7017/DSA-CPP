class Solution {
  public:
    bool checkCyle(vector<int>adj[],int src,unordered_map<int,
    bool>&visited,unordered_map<int,bool>&dfsVisited,vector<bool>&safeNode){
        visited[src]=true;
        dfsVisited[src]=true;
        safeNode[src]=false;
        for(auto nbr:adj[src]){
            if(!visited[nbr]){
                bool aageKeAnswer=checkCyle(adj,nbr,visited,dfsVisited,safeNode);
                if(aageKeAnswer==true){
                    return true;
                }
            }
            if(visited[nbr]==true && dfsVisited[nbr]==true){
                return true; // cycle present;
            }
        }
        dfsVisited[src]=false;
        safeNode[src]=true;
        return false;
    }
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        vector<int>ans;
        unordered_map<int,bool>visited,dfsVisited;
        vector<bool>safeNode(V,false);
        for(int i=0;i<V;i++){
            if(!visited[i]){
                checkCyle(adj,i,visited,dfsVisited,safeNode);
            }
        }
        for(int i=0;i<V;i++){
            if(safeNode[i]) ans.push_back(i);
        }
        return ans;
    }
};

// Time Complexity: O(V+E)
// Space Complexity: O(V+E)