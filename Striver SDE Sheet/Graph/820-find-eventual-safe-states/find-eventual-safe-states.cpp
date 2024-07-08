class Solution {
public:
    bool dfs(int src,vector<bool>&vis,vector<bool>&dfsCall,vector<bool>&safeNode,vector<vector<int>>& graph){
        vis[src]=true;
        dfsCall[src]=true;
        safeNode[src]=false;

        for(auto nbr:graph[src]){
            if(!vis[nbr]){
                int ans=dfs(nbr,vis,dfsCall,safeNode,graph);
                if(ans==true) return true;
            }
            if(vis[nbr] && dfsCall[nbr]) return true;
        }

        dfsCall[src]=false;
        safeNode[src]=true;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V=graph.size();
        vector<bool>dfsCall(V,false);
        vector<bool>safeNode(V,false);
        vector<bool>vis(V,false);
        vector<int>ans;
        for(int i=0;i<V;i++){
            dfs(i,vis,dfsCall,safeNode,graph);
        }
        for(int i=0;i<V;i++){
            if(safeNode[i]) ans.push_back(i);
        }
        sort(begin(ans),end(ans));
        return ans;
    }
};