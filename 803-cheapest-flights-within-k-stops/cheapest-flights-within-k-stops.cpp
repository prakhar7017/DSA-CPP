class Solution {
public:
    typedef pair<int, int> P;
    int solveUsinfBFS(int n, int src, int dest, int k,
                      unordered_map<int, vector<P>>& adj) {
        queue<P> q;
        q.push({src, 0});
        vector<int> dis(n, INT_MAX);
        dis[src]=0;
        int steps = 0;
        while (!q.empty() && steps <= k) {
            int size = q.size();
            while (size--) {
                int currNode = q.front().first;
                int currCost = q.front().second;
                q.pop();
                for(auto &it:adj[currNode]){
                    int nbrNode = it.first;
                    int nbrCost = it.second;

                    if(currCost+nbrCost<dis[nbrNode]){
                        dis[nbrNode]=currCost+nbrCost;
                        q.push({nbrNode,currCost+nbrCost});
                    }
                }
            }
            steps++;
        }

        return dis[dest];
    }
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                          int k) {
        unordered_map<int, vector<P>> adj;

        for (vector<int>& flight : flights) {
            int u = flight[0];
            int v = flight[1];
            int cost = flight[2];
            adj[u].push_back({v, cost});
        }
        int ans = solveUsinfBFS(n, src, dst, k, adj);
        return ans == INT_MAX ? -1 : ans;
    }
};