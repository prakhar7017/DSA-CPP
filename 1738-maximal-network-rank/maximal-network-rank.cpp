class Solution {
public:
    int solve(int n, vector<vector<int>>& roads) {
        unordered_map<int, unordered_set<int>> adj;

        for (vector<int>& road : roads) {
            int u = road[0];
            int v = road[1];
            adj[u].insert(v);
            adj[v].insert(u);
        }
        int maxRank = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int rank = adj[i].size() + adj[j].size();
                if (adj[i].find(j) != adj[i].end()) {
                    rank--;
                }
                maxRank = max(maxRank, rank);
            }
        }
        return maxRank;
    }
    int solve1(int n, vector<vector<int>>& roads) { // [[1,0]]  0-1 1-0
        vector<int> roadsConnected(n, 0);           // []
        vector<vector<bool>> isConnected(n, vector<bool>(n, false));

        for (vector<int>& road : roads) {
            int u = road[0];
            int v = road[1];
            roadsConnected[u]++;
            roadsConnected[v]++;
            isConnected[u][v] = true;
            isConnected[v][u] = true;
        }
        int maxRank = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int rank = roadsConnected[i] + roadsConnected[j];
                if (isConnected[i][j]) {
                    rank--;
                }
                maxRank = max(maxRank, rank);
            }
        }
        return maxRank;
    }
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        return solve1(n, roads);
    }
};