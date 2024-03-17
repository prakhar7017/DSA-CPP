class Solution {
public:
    int dijkstra(int src,int n,unordered_map<int,list<pair<int,int>>>&adjList,int &distanceThreshold){
        vector<int>dist(n,INT_MAX);
        set<pair<int,int>>st;
        dist[src]=0;
        st.insert({0,src});
        int reachAbleCities=0; // cities at  most having distanceThreshold distance

        while(!st.empty()){
            auto top=*st.begin();
            st.erase(st.begin());
            int nodeDist=top.first;
            int node=top.second;

            if(node!=src && nodeDist<=distanceThreshold)
                ++reachAbleCities;
            
            for(auto nbr:adjList[node]){
                int nbrNode=nbr.first;
                int nbrWt=nbr.second;
                int currDist=nodeDist+nbrWt;
                if(currDist<dist[nbrNode]){
                    auto it=st.find({dist[nbrNode],nbrNode}); // yha galti karuga 
                    if(it!=st.end()){
                        st.erase(it);
                    }
                    dist[nbrNode]=currDist;
                    st.insert({dist[nbrNode],nbrNode});
                }
            }
        }
        return reachAbleCities;
    }
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        unordered_map<int,list<pair<int,int>>>adjList;
        for(auto edge:edges){
            int &u=edge[0];
            int &v=edge[1];
            int &wt=edge[2];
            adjList[u].push_back({v,wt});
            adjList[v].push_back({u,wt});
        }
        int city=0;
        int minReachacleCities=INT_MAX;
        for(int i=0;i<n;i++){
            int reachAbleCount=dijkstra(i,n,adjList,distanceThreshold);
            if(reachAbleCount<=minReachacleCities){ // yha galti karuga ma
                minReachacleCities=reachAbleCount;
                city=i;
            }
        }
        return city;
    }
};

// time complexity: O(n^2)
// space complexity: O(n) + O(n^2) + O(n) = O(n^2)