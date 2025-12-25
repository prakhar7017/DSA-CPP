class Solution {
public:
    int ans = -1;
    void dfs(int u, vector<bool>& visited, vector<bool>& inRecursion,
             vector<int>& count, vector<int>& edges) {

        visited[u]=true;
        inRecursion[u]=true;

        int v = edges[u];
        if(v!=-1 && !visited[v]){
            count[v]=count[u]+1;
            dfs(v,visited,inRecursion,count,edges);
        } else if(v!=-1 && inRecursion[v]==true){
            // cycle detected
            ans = max(ans,count[u]-count[v]+1);
        }
        // backtrack
        inRecursion[u]=false;
    }
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<bool> visited(n, false);
        vector<bool> inRecursion(n, false);
        vector<int> count(n, 1);
        for (int i = 0; i < n; i++) {
            if (!visited[i])
                dfs(i, visited, inRecursion, count, edges);
        }
        return ans;
    }
};