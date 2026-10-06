class Solution {
public:
    typedef pair<int,int>P;
    int DJ(int n, int k,unordered_map<int,vector<P>>&adj){
        vector<int>result(n+1,INT_MAX);
        priority_queue<P,vector<P>,greater<P>>pq;
        pq.push({0,k});
        result[k]=0;

        while(!pq.empty()){
            int curr = pq.top().second;
            int d = pq.top().first;
            pq.pop();
            for(auto [v,wt]:adj[curr]){
                if(d+wt<result[v]){
                    result[v]=d+wt;
                    pq.push({d+wt,v});
                }
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            if(result[i]==INT_MAX) return -1;
            ans = max(ans,result[i]);
        }
        return ans;
    }
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int,vector<P>>adj;
        for(auto &time:times){
            int u = time[0];
            int v = time[1];
            int wt = time[2];
            adj[u].push_back({v,wt});
        }

        return DJ(n,k,adj);
    }
};