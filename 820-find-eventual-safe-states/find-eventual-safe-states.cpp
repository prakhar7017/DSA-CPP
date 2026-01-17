class Solution {
public:
    bool isCycleExist(int node,vector<bool>&vis,vector<bool>&inRec,vector<vector<int>>& graph){
        vis[node]=true;
        inRec[node]=true;

        for(int &nbrNode:graph[node]){
            if(!vis[nbrNode]){
                bool checkCycle = isCycleExist(nbrNode,vis,inRec,graph);
                if (checkCycle) return true;
            } else if(inRec[nbrNode]){
                return true;
            }
        }
        inRec[node]=false;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<bool>vis(n,false);
        vector<bool>inRec(n,false);

        for(int i=0;i<n;i++){
            isCycleExist(i,vis,inRec,graph);
        }

        vector<int>ans;
        for(int i=0;i<n;i++){
            if(inRec[i]==false) ans.push_back(i);
        }
        return ans;
    }
};