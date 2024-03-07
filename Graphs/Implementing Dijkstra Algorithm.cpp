class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        vector<int>dist(V+1,INT_MAX);
        set<pair<int,int>>st; //set<pair<dist,node>>
        
        // initial State
        st.insert({0,S});
        dist[S]=0;
        
        // distance Updation
        while(!st.empty()){
            auto topElement=st.begin(); // return iterator
            pair<int,int>topPair=*topElement; // dereference iterator
            int srcDist=topPair.first;
            int srcNode=topPair.second;
            
            // delete the topNode
            st.erase(st.begin());
            
                for(auto nbr:adj[srcNode]){
                    int nbrNode=nbr[0];
                    int nbrDist=nbr[1];
                    
                    if(srcDist+nbrDist<dist[nbrNode]){ // updaint time
                        // founded new Shorted distance
                        // now update
                        auto prevEntry=st.find({dist[nbrNode],nbrNode});
                        if(prevEntry!=st.end()){
                            st.erase(prevEntry);
                        }
                        dist[nbrNode]=srcDist+nbrDist;
                        st.insert({dist[nbrNode],nbrNode});
                    }
                }
            
        }
        return dist;
        
    }
};

// Time Complexity: O((V+E)logV)
// Space Complexity: O(V+E)
