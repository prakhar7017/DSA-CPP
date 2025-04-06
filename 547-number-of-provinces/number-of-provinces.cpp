class Solution {
public:
    int cities;
    void solveUsingBFS(vector<vector<int>>& isConnected,int city,vector<bool>&vis){
        queue<int>q;
        vis[city]=true;
        q.push(city);

        while(!q.empty()){
            int frontCity=q.front();
            q.pop();
            for(int neighbourCity=0;neighbourCity<cities;neighbourCity++){
                if(isConnected[frontCity][neighbourCity]==1 && !vis[neighbourCity]){
                    q.push(neighbourCity);
                    vis[neighbourCity]=true;
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        cities=isConnected.size();
        vector<bool>vis(cities,false);
        int provinces=0;
        for(int city=0;city<cities;city++){
            if(!vis[city]){
                solveUsingBFS(isConnected,city,vis);
                provinces++;
            }
        }
        return provinces;
    }
};