class Solution {
public:
    typedef pair<int,int>P;
    int n;
    int prims(unordered_map<int,vector<P>>adj){
        priority_queue<P,vector<P>,greater<P>>pq;
        vector<bool>inmst(n,false);
        int sum =0 ;
        pq.push({0,0});
        while(!pq.empty()){
            int wt = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            if(inmst[u]) continue;
            inmst[u]=true;
            sum+=wt;

            for(auto [v,cost]:adj[u]){
                if(!inmst[v]){
                    pq.push({cost,v});
                }
            }
        }
        return sum;
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        n = points.size();
        unordered_map<int,vector<P>>adj;
        for(int i=0;i<n;i++){
            int x1 = points[i][0];
            int y1 = points[i][1];
            for(int j=i+1;j<n;j++){
                int x2 = points[j][0];
                int y2 = points[j][1];


                int d = abs(x1-x2)+abs(y1-y2);
                adj[i].push_back({j,d});
                adj[j].push_back({i,d});
            }
        }

        return prims(adj);
    }
};