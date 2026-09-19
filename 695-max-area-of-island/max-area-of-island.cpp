class Solution {
public:
    typedef pair<int,int>P;
    vector<vector<int>>directions={{-1,0},{0,1},{1,0},{0,-1}};
    bool isSafe(int x,int y,vector<vector<bool>>&vis,vector<vector<int>>& grid){
        if(x>=0 && y>=0 && x<grid.size() && y<grid[0].size() && !vis[x][y] && grid[x][y]!=0) return true;
        return false;
    }
    int BFS(int x,int y, vector<vector<bool>>&vis,vector<vector<int>>& grid){
        queue<P>q;
        q.push({x,y});
        vis[x][y]=true;
        int area = 1;

        while(!q.empty()){
            int currX = q.front().first;
            int currY = q.front().second;
            q.pop();
            // area++;
            for(vector<int>&dir:directions){
                int newX = currX + dir[0];
                int newY = currY + dir[1];

                if(isSafe(newX,newY,vis,grid)){
                    vis[newX][newY]=true;
                    q.push({newX,newY});
                    area++;
                }
            }
        }
        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        vector<vector<bool>>vis(grid.size(),vector<bool>(grid[0].size(),false));
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1 && !vis[i][j]) ans= max(ans,BFS(i,j,vis,grid));
            }
        }
        return ans;
    }
};