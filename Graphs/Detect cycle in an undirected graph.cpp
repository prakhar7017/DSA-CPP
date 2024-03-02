
// DFS approach
class Solution {
  public:
    bool checkCycle(int src,int parent,unordered_map<int,bool>&vis,vector<int>adj[]){
        vis[src]=true;
        for(auto nbr:adj[src]){
            if(nbr==parent) continue;
            if(!vis[nbr]){
                bool ans=checkCycle(nbr,src,vis,adj);
                if(ans){
                    return true;
                }
            }else if(vis[nbr]==true){
                return true;
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        unordered_map<int,bool>vis;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                int parent=-1;
                bool ans=checkCycle(i,parent,vis,adj);
                if(ans) return true;
            }
        }
        return false;
    }
};

// time compelxity: O(V+E)
// space complexity: O(V)

// BFS approach
class Solution {
  public:
    bool checkCycle(int src,unordered_map<int,int>&parent,unordered_map<int,bool>&vis,vector<int> adj[]){
        queue<int>q;
        q.push(src);
        vis[src]=true;
        parent[src]=-1;
        
        while(!q.empty()){
            int frontNode=q.front();
            q.pop();
            
            for(auto nbr:adj[frontNode]){
                if(nbr==parent[frontNode]) continue;
                if(!vis[nbr]){
                    q.push(nbr);
                    vis[nbr]=true;
                    parent[nbr]=frontNode;
                }else if(vis[nbr]==true){
                    return true;
                }
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        unordered_map<int,bool>vis;
        unordered_map<int,int>parent;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                bool ans=checkCycle(i,parent,vis,adj);
                if(ans) return true;
            }
        }
        return false;
    }
};

// time complexity: O(V+E)
// space complexity: O(V)