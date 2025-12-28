class Solution {
public:
    typedef pair<int,int>P;
    bool isSafe(int x,int y,vector<vector<int>>& grid){
        if(x>=0 && x<grid.size() && y>=0 && y<grid[0].size() && grid[x][y]==0) return true;
        return false;
    }
    vector<vector<int>>directions{{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        if(rows==0 || cols == 0 || grid[0][0]==1 || grid[rows-1][cols-1]==1) return -1;
        vector<vector<bool>>vis(rows,vector<bool>(cols,false));

        queue<P>q;
        q.push({0,0});
        vis[0][0]=true;
        int steps = 1;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                auto [currX,currY] = q.front();
                q.pop();

                if(currX == rows-1 && currY == cols-1) {
                    return steps;
                }

                for(vector<int>&dir:directions){
                    int newX = dir[0]+currX;
                    int newY = dir[1]+currY;

                    if(isSafe(newX,newY,grid) && vis[newX][newY]==false){
                        q.push({newX,newY});
                        vis[newX][newY]=true;
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};