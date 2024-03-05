// index is used as a node here. 
class Solution {
public:
    void dfs(int src,unordered_map<int,bool>&vis,vector<vector<int>>& isConnected,int n){
        vis[src]=true;
        int row=src;
        for(int col=0;col<n;col++){
            if(isConnected[row][col]==1 && src!=col && !vis[col]){
                dfs(col,vis,isConnected,n);
            }
        }
    }
    void bfs(int src,unordered_map<int,bool>&vis,vector<vector<int>>& isConnected,int n){
        queue<int>q;
        // initial State
        q.push(src);
        vis[src]=true;
        while(!q.empty()){
            int row=q.front();
            q.pop();
            for(int colIndex=0;colIndex<n;colIndex++){
                if(isConnected[row][colIndex]==1 && src!=colIndex && !vis[colIndex]){
                    q.push(colIndex);
                    vis[colIndex]=true;
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        unordered_map<int,bool>vis;
        int count=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                bfs(i,vis,isConnected,n);
                count++;
            }
        }
        return count;
    }
};

// Time Complexity: O(n^2) where n is the number of cities.
// Space Complexity: O(n) where n is the number of cities. The visited array of size n is used.
// why used visited array? 0->1 to prevent the same city to be visited again.
                        //  <-                             

// dfs Solution