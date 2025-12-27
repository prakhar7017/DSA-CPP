class Solution {
public:
    vector<int>parent;
    vector<int>rank;

    int findParent(int x) {
        if(x == parent[x]) return x;
        return parent[x] = findParent(parent[x]);
    }

    void Union(int x, int y){
        x = findParent(x);
        y = findParent(y);

        if(x == y) return ;

        if(rank[x]<rank[y]){
            parent[x]=y;
        } else if (rank[x]>rank[y]){
            parent[y]=x;
        } else {
            parent[y]=x;
            rank[x]++;
        }
    }
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        rank.resize(n,0);
        parent.resize(n);
        iota(begin(parent),end(parent),0);

        for(int i = 0;i<queries.size();i++) queries[i].push_back(i);

        auto lambda = [&](vector<int>& v1,vector<int>&v2){
            return v1[2]<v2[2];
        };

        sort(begin(edgeList),end(edgeList),lambda);
        sort(begin(queries),end(queries),lambda);

        vector<bool>ans(queries.size());
        int kha_tak_edge_ban_chuka_hu = 0;
        for(int i=0;i<queries.size();i++){
            vector<int> query = queries[i];
            int src = query[0];
            int dest = query[1];
            int limit = query[2];
            int idx = query[3];

            while(kha_tak_edge_ban_chuka_hu< edgeList.size() && 
            edgeList[kha_tak_edge_ban_chuka_hu][2]<limit){
                Union(edgeList[kha_tak_edge_ban_chuka_hu][0],edgeList[kha_tak_edge_ban_chuka_hu][1]);
                kha_tak_edge_ban_chuka_hu++;
            }

            if(findParent(src) == findParent(dest)) {
                ans[idx] = true;
            } else {
                ans[idx] = false;
            }
        }
        return ans;
    }
};