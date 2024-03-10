#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>
#include <limits.h>
using namespace std;
template <typename T>
class Graph
{
public:
    unordered_map<T, list<pair<T, int>>> adjList;
    void addEdge(T u, T v, int wt, bool dir)
    {
        if (dir == 0)
        {
            adjList[u].push_back({v, wt});
            adjList[v].push_back({u, wt});
        }
        else
        {
            adjList[u].push_back({v, wt});
        }
    }

    void floydWarshal(int n)
    {
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX)); // n*n ka matrix banaya, sabhi elements ko infinity se initialize kiya
        // hu, 1e9 se bhi initialize kar sakte hh

        // diagonal par 0
        for (int i = 0; i < n; i++)
        {
            dist[i][i] = 0;
        }

        // kuch wt graph ka ander bhi honge, unhe bhi update karo
        for (auto a : adjList)
        {
            for (auto b : a.second)
            {
                T u = a.first;
                T v = b.first;
                int wt = b.second;
                dist[u][v] = wt;
            }
        }

        // main logic
        for (int helper = 0; helper < n; helper++)
        {
            for (int src = 0; src < n; src++)
            {
                for (int dest = 0; dest < n; dest++)
                {
                    if (dist[src][helper] != INT_MAX && dist[helper][dest] != INT_MAX) // ( ( IMPORTANT CONDITION ) agar koi bhi infinity nahi h toh hi update karo, kuki infinity se koi bhi number add karo toh infinity hi rahega, igar iska dhyan nhi rakha toh overflow ho sakta h.
                        dist[src][dest] = min(dist[src][dest], dist[src][helper] + dist[helper][dest]);
                }
            }
        }

        // printing dist;
        for (int i = 0; i < dist.size(); i++)
        {
            for (int j = 0; j < dist[0].size(); j++)
            {
                cout << dist[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    Graph<int> g;
    g.addEdge(0, 3, 5, 1);
    g.addEdge(0, 1, 3, 1);
    g.addEdge(1, 0, 2, 1);
    g.addEdge(1, 3, 4, 1);
    g.addEdge(3, 2, 2, 1);
    g.addEdge(2, 1, 1, 1);
    g.floydWarshal(4);

    return 0;
}
// time complexity: O(n^3)
// space complexity: O(n^2)
//---------------------------------------------------------------------
void floydWarshal(int n)
{
    vector<vector<int>> dist(n, vector<int>(n, 1e9)); // wh have used 1e9 
    // so no need to check for infinity in blow condotion

    // diagonal par 0
    for (int i = 0; i < n; i++)
    {
        dist[i][i] = 0;
    }

    // kuch wt graph ka ander bhi honge, unhe bhi update karo
    for (auto a : adjList)
    {
        for (auto b : a.second)
        {
            T u = a.first;
            T v = b.first;
            int wt = b.second;
            dist[u][v] = wt;
        }
    }

    // main logic
    for (int helper = 0; helper < n; helper++)
    {
        for (int src = 0; src < n; src++)
        {
            for (int dest = 0; dest < n; dest++)
            {
                dist[src][dest] = min(dist[src][dest], dist[src][helper] + dist[helper][dest]); // only diff in above code and this code
            }
        }
    }

    // printing dist;
    for (int i = 0; i < dist.size(); i++)
    {
        for (int j = 0; j < dist[0].size(); j++)
        {
            cout << dist[i][j] << " ";
        }
        cout << endl;
    }
}
//---------------------------------------------------------------------
// another way to write the same code (GFG) specific
class Solution
{
public:
    void shortest_distance(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        for (int helper = 0; helper < n; helper++)
        {
            for (int src = 0; src < n; src++)
            {
                for (int dest = 0; dest < n; dest++)
                {
                    if (matrix[src][helper] != -1 && matrix[helper][dest] != -1)
                    {
                        if (matrix[src][dest] == -1 || matrix[src][helper] + matrix[helper][dest] < matrix[src][dest])
                        {
                            // If no path from src to dest exists or going through helper gives a shorter path
                            matrix[src][dest] = matrix[src][helper] + matrix[helper][dest];
                        }
                    }
                }
            }
        }
    }
};