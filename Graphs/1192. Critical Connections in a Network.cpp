class Solution {
public:
    void createAdj(vector<vector<int>>& connections,unordered_map<int,list<int>>&adjList){
        for(auto i:connections){
            int u=i[0];
            int v=i[1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
    }
    void findBridge(int src,int parent,vector<int>&low,vector<int>&tin,int &timer,unordered_map<int,bool>&vis,
    unordered_map<int,list<int>>&adjList,vector<vector<int>>&ans){
        vis[src]=true;
        low[src]=timer;
        tin[src]=timer;
        timer++;

        for(auto nbr:adjList[src]){
            if(nbr==parent) continue;
            if(!vis[nbr]){
                //dfs call
                findBridge(nbr,src,low,tin,timer,vis,adjList,ans);
                // update low
                low[src]=min(low[src],low[nbr]);
                // check bridge
                if(low[nbr]>tin[src]){ // be carefull  
                    vector<int>temp;
                    temp.push_back(src);
                    temp.push_back(nbr);
                    ans.push_back(temp);
                }
            }else{
                 // already vis node
                low[src]=min(low[src],tin[nbr]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        unordered_map<int,list<int>>adjList;
        createAdj(connections,adjList);
        unordered_map<int,bool>vis;
        vector<int>low(n);
        vector<int>tin(n);
        int timer=1;
        vector<vector<int>>ans;
        findBridge(0,-1,low,tin,timer,vis,adjList,ans);
        return ans;
    }
};

// time complexity: O(n)
// space complexity: O(n)
