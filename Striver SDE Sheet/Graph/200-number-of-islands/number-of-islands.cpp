class Solution {
public:
    typedef pair<int,int> P;
    vector<vector<int>>directions{{-1,0},{0,1},{1,0},{0,-1}};
    bool isSafe(int x,int y,vector<vector<char>>& grid){
        return x>=0 && x<grid.size() && y>=0 && y<grid[0].size(); 
    }
    void bfs(int row,int col,vector<vector<char>>& grid){
        queue<P>q;
        q.push({row,col});
        grid[row][col]='0';

        while(!q.empty()){
            P topPair=q.front();
            q.pop();
            int x=topPair.first;
            int y=topPair.second;

            for(auto dir:directions){
                int newX=x+dir[0];
                int newY=y+dir[1];

                if(isSafe(newX,newY,grid) && grid[newX][newY]!='0'){
                    q.push({newX,newY});
                    grid[newX][newY]='0';
                }
            }

        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int rows=grid.size();
        int cols=grid[0].size();
        int count=0;
        for(int row=0;row<rows;row++){
            for(int col=0;col<cols;col++){
                if(grid[row][col]!='0'){
                    bfs(row,col,grid);
                    count++;
                }
            }
        }
        return count;
    }
};