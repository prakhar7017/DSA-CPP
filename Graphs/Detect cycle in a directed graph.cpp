class Solution {
  public:
    bool checkCycle(int src,unordered_map<int,bool>&vis,unordered_map<int,bool>&dfsTrack,vector<int> adj[]){
        vis[src]=true;
        dfsTrack[src]=true;
        for(auto nbr:adj[src]){
            if(!vis[nbr]){
                bool ans=checkCycle(nbr,vis,dfsTrack,adj);
            }
            if(vis[nbr]==true && dfsTrack[nbr]==true){
                return true;
            }
        }
        // backTrack 
        dfsTrack[src]=false;
        return false;
        
    }
    bool isCyclic(int V, vector<int> adj[]) {
        unordered_map<int,bool>vis;
        unordered_map<int,bool>dfsTrack;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                bool ans=checkCycle(i,vis,dfsTrack,adj);
                if(ans) return true;
            }
        }
        return false;
    }
};

// time complexity: O(V+E)
// space complexity: O(V)