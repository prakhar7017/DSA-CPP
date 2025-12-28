class Solution {
public:
    typedef long long ll;
    int BFS(int node,int n,unordered_map<int,vector<int>>&adj){
        queue<int>q;
        vector<int>vis(n,false);
        q.push(node);
        vis[node]=true;
        int count = 0;
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            count++;
            for(int &v:adj[curr]){
                if(!vis[v]){
                    q.push(v);
                    vis[v]=true;
                }
            }
        }
        return count;
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        unordered_map<int,vector<int>>adj;
        for(int i=0;i<n;i++){
            ll xi = bombs[i][0];
            ll yi = bombs[i][1];
            ll ri = bombs[i][2];
            ll sqr = ri*ri;
            for(int j=0;j<n;j++){
                if (i==j) continue;
                ll xj = bombs[j][0];
                ll yj = bombs[j][1];

                if((((xi-xj)*(xi-xj))+((yi-yj)*(yi-yj)))<=sqr){
                    adj[i].push_back(j);
                }
            }
        }

        int maxBombs = 0;

        for(int i=0;i<n;i++){
            maxBombs = max(maxBombs,BFS(i,n,adj));
            if (maxBombs == n) break;
        }
        return maxBombs;
    }
};