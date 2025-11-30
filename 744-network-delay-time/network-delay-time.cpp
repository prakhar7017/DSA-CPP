class Solution {
public:
    typedef pair<int,int>P;
    int solveUsingDJ(vector<vector<int>>& times, int n, int k){
        unordered_map<int,vector<P>>adj;
        for(vector<int>&time:times){
            int u = time[0];
            int v = time[1];
            int wt = time[2];
            adj[u].push_back({v,wt});
        }

        priority_queue<P,vector<P>,greater<P>>pq;

        vector<int>result(n+1,INT_MAX);
        result[k]=0;
        pq.push({0,k});

        while(!pq.empty()){
            int dist = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for(auto &it: adj[node]){
                int adjNode = it.first;
                int adjDist = it.second;

                if(dist+adjDist<result[adjNode]){
                    result[adjNode]=dist+adjDist;
                    pq.push({dist+adjDist,adjNode});
                }
            }
        }

        int ans= INT_MIN;
        for(int i=1;i<=n;i++){
            ans = max(ans,result[i]);
        }

        return ans == INT_MAX ? -1 : ans;

    }
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        return solveUsingDJ(times,n,k);
    }
};