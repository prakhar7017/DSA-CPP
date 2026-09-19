class Solution {
public:
    typedef pair<int,int>P;
    vector<vector<int>>directions={{-1,0},{0,1},{1,0},{0,-1}};
    bool isSafe(int x,int y,vector<vector<bool>>&vis,vector<vector<char>>& grid){
        if(x>=0 && x<grid.size() && y>=0 && y<grid[0].size() && grid[x][y]!='0' && !vis[x][y]) return true;
        return false;
    }
    void BFS(int x,int y,vector<vector<bool>>&vis,vector<vector<char>>& grid){
        queue<P>q;
        q.push({x,y});
        vis[x][y]=true;

        while(!q.empty()){
            int currX = q.front().first;
            int currY =  q.front().second;

            q.pop();

            for(vector<int>&dir:directions){
                int newX = currX + dir[0];
                int newY = currY + dir[1];

                if(isSafe(newX,newY,vis,grid)){
                    q.push({newX,newY});
                    vis[newX][newY]=true;
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<bool>>vis(grid.size(),vector<bool>(grid[0].size(),false));
        int count=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    BFS(i,j,vis,grid);
                    count++;
                }
            }
        }
        return count;
    }
};