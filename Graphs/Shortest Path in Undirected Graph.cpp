#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>
using namespace std;

vector<int> shortestPath(vector<pair<int,int>> edges, int n, int m, int s, int t) {
    vector<int> ans;
    queue<int> q;
    unordered_map<int,int> parent;
    unordered_map<int,bool> vis;

    // Construct adjacency list from edges
    vector<vector<int>> adjList(n);
    for (auto edge : edges) {
        adjList[edge.first].push_back(edge.second);
        adjList[edge.second].push_back(edge.first); // Consider undirected edges
    }

    // Initial State
    q.push(s);
    vis[s] = true;
    parent[s] = -1;

    while (!q.empty()) {
        int frontNode = q.front();
        q.pop();
        for (int nbr : adjList[frontNode]) { // Corrected the iteration over neighbors
            if (!vis[nbr]) {
                q.push(nbr);
                vis[nbr] = true;
                parent[nbr] = frontNode;
            }
        }
    }

    // Retrieve the shortest path
    while (t != -1) {
        ans.push_back(t);
        t = parent[t];
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
