class Solution {
public:
    void dfs1(int src, stack<int>& st, unordered_map<int, bool>& vis1, vector<vector<int>>& adj) {
        vis1[src] = true;
        for (auto i : adj[src]) {
            if (!vis1[i]) {
                dfs1(i, st, vis1, adj);
            }
        }
        st.push(src);
    }

    void dfs2(int src, unordered_map<int, bool>& vis2, vector<vector<int>>& adjList) {
        vis2[src] = true;
        for (auto i : adjList[src]) {
            if (!vis2[i]) {
                dfs2(i, vis2, adjList);
            }
        }
    }

    int kosaraju(int V, vector<vector<int>>& adj) {
        stack<int> ordering;
        unordered_map<int, bool> vis1;
        
        for (int i = 0; i < V; i++) {
            if (!vis1[i]) {
                dfs1(i, ordering, vis1, adj);
            }
        }

        // Reverse the edges to create the reversed adjacency list
        vector<vector<int>> reversedAdjList(V);
        for (int i = 0; i < V; i++) {
            for (auto j : adj[i]) { // i->j
                reversedAdjList[j].push_back(i); //j->i
            }
        }

        int count = 0;
        unordered_map<int, bool> vis2;
        while (!ordering.empty()) {
            int top = ordering.top();
            ordering.pop();
            if (!vis2[top]) {
                dfs2(top, vis2, reversedAdjList);
                count++;
            }
        }
        return count;
    }
};

// time complexity: O(V+E)
// space complexity:O(V+E)