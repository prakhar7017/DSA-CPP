class Solution {
public:
    vector<int> solveUsinfDFS(int currNode,int parent, vector<int>&ans,string &labels,unordered_map<int,vector<int>>&adj){
        vector<int>freq(26,0);
        for(int child:adj[currNode]){
            if(child == parent) continue;
            vector<int>childFreq = solveUsinfDFS(child,currNode,ans,labels,adj);

            for(int i=0;i<26;i++){
                freq[i]+=childFreq[i];
            }
        }

        int idx = labels[currNode]-'a';
        freq[idx]++;
        ans[currNode]=freq[idx];
        return freq;
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        unordered_map<int,vector<int>>adj;
        for(vector<int>&edge:edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int>ans(n);
        solveUsinfDFS(0,-1,ans,labels,adj);
        return ans;
    }
};