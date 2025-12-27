class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    int findParent(int x) {
        if (x == parent[x])
            return x;
        return parent[x] = findParent(parent[x]);
    }

    bool Union(int x, int y) {
        x = findParent(x);
        y = findParent(y);

        if (x == y)
            return false;

        if (rank[x] < rank[y]) {
            parent[x] = y;
        } else if (rank[x] > rank[y]) {
            parent[y] = x;
        } else {
            parent[y] = x;
            rank[x]++;
        }

        return true;
    }

    bool isSimilar(string& s1, string& s2) {
        int n = s1.length();
        int diff = 0;
        for (int i = 0; i < n; i++) {
            if (s1[i] != s2[i]) {
                diff++;
                if (diff > 2)
                    return false;
            }
        }
        return diff <= 2;
    }
    int solveUsingDSU(vector<string>& strs) {
        int n = strs.size();
        rank.resize(n, 0);
        parent.resize(n);
        iota(begin(parent), end(parent), 0);

        int components = n;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (isSimilar(strs[i], strs[j])) {
                    if (Union(i, j))
                        components--;
                }
            }
        }
        return components;
    }

    int solveUsingBFS(vector<string>& strs) {
        int n = strs.size();
        vector<bool> vis(n, false);
        int components = 0;
        for (int i = 0; i < n; i++) {
            if(!vis[i]){
                vis[i]=true;
                queue<int>q;
                q.push(i);
                components++;

                while(!q.empty()){
                    int curr = q.front();
                    q.pop();

                    for(int j=0;j<n;j++){
                        if(!vis[j] && isSimilar(strs[curr],strs[j])){
                            q.push(j);
                            vis[j]=true;
                        }
                    }
                }
            }
        }
        return components;
    }
    int numSimilarGroups(vector<string>& strs) {
        // return solveUsingDSU(strs);
        return solveUsingBFS(strs);
    }
};