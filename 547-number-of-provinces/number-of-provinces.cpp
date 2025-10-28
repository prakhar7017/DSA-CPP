class Solution {
public:
    void checkDFS(int city,vector<bool>&vis,vector<vector<int>>& isConnected){
        vis[city]=true;

        for(int neighCity=0;neighCity<isConnected.size();neighCity++){
            if(isConnected[city][neighCity] && !vis[neighCity]){
                checkDFS(neighCity,vis,isConnected);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int cities = isConnected.size();
        vector<bool>vis(cities,false);
        int provinces = 0;

        for (int city = 0; city <cities; city++) {
            if(!vis[city]){
                checkDFS(city,vis,isConnected);
                provinces++;
            }
        }
        return provinces;
    }
};