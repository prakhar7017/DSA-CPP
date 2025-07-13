class Solution {
public:
    vector<vector<int>>directions{{0,1},{1,0}};
    bool isSafe(int x,int y,int rows,int cols){
        return x>=0 && x<rows && y>=0 && y<cols;
    }
    int solve(int x,int y,int rows,int cols,vector<vector<int>>&grid){
        if(x==rows-1 && y==cols-1) return 1;
        if(grid[x][y]!=-1) return grid[x][y];
        int totalPaths=0;
        for(vector<int>&dir:directions){
            int newX=x+dir[0];
            int newY=y+dir[1];
            if(isSafe(newX,newY,rows,cols)){
                totalPaths+=solve(newX,newY,rows,cols,grid);
            }
        }
        return grid[x][y]=totalPaths;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>grid(m,vector<int>(n,-1));
        return solve(0,0,m,n,grid);
    }
};