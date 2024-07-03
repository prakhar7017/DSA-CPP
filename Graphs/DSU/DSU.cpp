vector<int> rank;
vector<int> parent;
int findParent(int node, vector<int> &parent)
{
    if (node == parent[node])
    {
        return node;
    }
    return parent[node] = findParent(parent[node], parent);
}
void unionSet(int u, int v, vector<int> &parent, vector<int> &rank)
{
    u = findParent(u, parent);
    v = findParent(v, parent);

    if (u == v)
    {
        parent[v] = u;
        rank[u]++;
    }
    else if (rank[u] < rank[v])
    {
        parent[u] = v;
    }
    else
    { // rank[u]>rank[v]
        parent[v] = u;
    }
}

