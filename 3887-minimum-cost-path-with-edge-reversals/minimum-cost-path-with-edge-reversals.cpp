class Solution {
public:
    typedef pair<int,int>P; // {node,wt};
    int minCost(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<P>>adj;

        for(vector<int>&edge:edges){
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            adj[u].push_back({v,wt});
            adj[v].push_back({u,2*wt});
        }

        priority_queue<P,vector<P>,greater<P>>pq;
        vector<int>result(n,INT_MAX);

        pq.push({0,0});
        result[0]=0;

        while(!pq.empty()){
            int currDist = pq.top().first;
            int currNode = pq.top().second;
            pq.pop();

            if(currNode == n-1) return result[n-1];
            for(auto [nxtNode,nxtDist]:adj[currNode]){
                if(currDist+nxtDist<result[nxtNode]){
                    result[nxtNode]=currDist+nxtDist;
                    pq.push({result[nxtNode],nxtNode});
                }
            }

        }
        return -1;
    }
};