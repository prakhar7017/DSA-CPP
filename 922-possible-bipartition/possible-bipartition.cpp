class Solution {
public:
    bool checkBiPartite(int node, vector<int>& color,
                        unordered_map<int, vector<int>>& adj) {
        queue<int>q;                    
        q.push(node);
        color[node]=1;

        while(!q.empty()){
            int currNode = q.front();
            q.pop();
            for(int &adjNode:adj[currNode]){
                if(color[adjNode]==-1){
                    q.push(adjNode);
                    color[adjNode]=1-color[currNode];
                } else if(color[adjNode]==color[currNode]) return false;
            }
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        unordered_map<int, vector<int>> adj;
        for (vector<int>& dislike : dislikes) {
            int u = dislike[0];
            int v = dislike[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> color(n + 1, -1);

        for (int i = 1; i <= n; i++) {
            if (color[i] == -1) {
                if (checkBiPartite(i, color, adj) == false)
                    return false;
            }
        }
        return true;
    }
};