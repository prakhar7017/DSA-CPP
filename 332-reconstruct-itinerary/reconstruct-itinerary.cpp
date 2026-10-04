class Solution {
public:
    vector<string>ans;
    void DFS(string start,unordered_map<string,multiset<string>>&adj){
        while(!adj[start].empty()){
            string nextAirport = *adj[start].begin();
            //erase the airport for not visiting again.
            adj[start].erase(adj[start].begin());
            DFS(nextAirport,adj);
        }
        ans.push_back(start);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        
        unordered_map<string,multiset<string>>adj;
        for(auto &t:tickets){
            adj[t[0]].insert(t[1]);
        }
        string startAirport = "JFK";
        DFS(startAirport,adj);
        reverse(begin(ans),end(ans));
        return ans;
    }
};