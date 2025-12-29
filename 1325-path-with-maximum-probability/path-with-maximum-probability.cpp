class Solution {
public:
    typedef pair<double,int>P;
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        unordered_map<int,vector<pair<int,double>>>adj;
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            double prob = succProb[i];
            adj[u].push_back({v,prob});
            adj[v].push_back({u,prob});
        }
        priority_queue<P>q;
        vector<double>prob(n,0.0);
        vector<bool>vis(n,false);
        q.push({1.0,start_node});
        prob[start_node]=1.0;

        while(!q.empty()){
            double currProb = q.top().first;
            int currNode = q.top().second;
            q.pop();
            if(vis[currNode]) continue;
            vis[currNode]=true;
            for(auto &it:adj[currNode]){
                int neighNode = it.first;
                double neighProb = it.second;

                if(!vis[neighNode]){
                    if(currProb*neighProb>prob[neighNode]){
                        prob[neighNode]=currProb*neighProb;
                        q.push({prob[neighNode],neighNode});

                    }
                }
            }
        }

        return prob[end_node];
    }
};