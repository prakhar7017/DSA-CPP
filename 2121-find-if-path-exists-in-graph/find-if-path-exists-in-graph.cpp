class Solution {
public:
    bool solveUsingBFS(int& source, int& destination,
                       unordered_map<int, bool>& vis,
                       unordered_map<int, vector<int>>& adj) {
        queue<int> q;
        q.push(source);
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            if (curr == destination)
                return true;
            for (auto nbr : adj[curr]) {
                if (!vis[nbr]) {
                    q.push(nbr);
                    vis[nbr]=true;
                }
            }
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source,
                   int destination) {
        unordered_map<int, vector<int>> adj;
        for (vector<int>& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        unordered_map<int,bool>vis;
        return solveUsingBFS(source, destination,vis,adj);
    }
};