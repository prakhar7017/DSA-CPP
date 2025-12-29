class Solution {
public:
    bool DFS(int src,vector<bool>&vis,vector<bool>&inRec,vector<vector<int>>& graph){
        vis[src]=true;
        inRec[src]=true;

        for(int &v:graph[src]){
            if(!vis[v]){
                bool isCycle = DFS(v,vis,inRec,graph);
                if (isCycle) return true;
            } else if(inRec[v]==true) return true;
        }

        inRec[src]=false;
        return false;

    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<bool>vis(n,false);
        vector<bool>inRec(n,false);
        vector<int>ans;

        for(int i=0;i<n;i++){
            DFS(i,vis,inRec,graph);
        }

        for(int i=0;i<n;i++){
            if(!inRec[i]) ans.push_back(i);
        }

        return ans;
    }
};