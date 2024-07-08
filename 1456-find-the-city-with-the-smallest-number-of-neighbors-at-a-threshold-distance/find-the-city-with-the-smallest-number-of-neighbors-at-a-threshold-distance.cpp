class Solution {
public:
    int dijkstra(int src,int &n,int &distanceThreshold,unordered_map<int,list<pair<int,int>>>&adjList){
        vector<int>dist(n+1,INT_MAX);
        set<pair<int,int>>st;
        dist[src]=0;
        st.insert({0,src});
        int minReachableCities=0;

        while(!st.empty()){
            auto topPair=*st.begin();
            st.erase(st.begin());
            int nodeDist=topPair.first;
            int node=topPair.second;

            if(node!=src && nodeDist<=distanceThreshold){
                minReachableCities++;
            }

            for(auto nbr:adjList[node]){
                int nbrNode=nbr.first;
                int nbrDist=nbr.second;

                if(nodeDist+nbrDist<dist[nbrNode]){
                    auto it =st.find({dist[nbrNode],nbrNode});
                    if(it!=st.end()){
                        st.erase(it);
                    }
                    dist[nbrNode]=nodeDist+nbrDist;
                    st.insert({nodeDist+nbrDist,nbrNode});
                }
            }
        }
        return minReachableCities;
    }
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        unordered_map<int,list<pair<int,int>>>adjList;
        // adjList
        for(auto edge:edges){
            int u=edge[0];
            int v=edge[1];
            int wt=edge[2];
            adjList[u].push_back({v,wt});
            adjList[v].push_back({u,wt});
        }

        int city=0;
        int minReachableCities=INT_MAX;
        for(int i=0;i<n;i++){
            int reachableCities=dijkstra(i,n,distanceThreshold,adjList);
            if(reachableCities<=minReachableCities){
                minReachableCities=reachableCities;
                city=i;
            }
        }
        return city;
    }
};