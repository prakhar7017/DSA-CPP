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
    int solveUsingTab(int rows,int cols){
        vector<vector<int>>grid(rows,vector<int>(cols,0));
        grid[0][0]=1;
        for(int col=1;col<cols;col++) grid[0][col]=1;
        for(int row=1;row<rows;row++) grid[row][0]=1;

        for(int row=1;row<rows;row++){
            for(int col=1;col<cols;col++){
                grid[row][col]=grid[row-1][col]+grid[row][col-1];
            }
        }
        return grid[rows-1][cols-1];
    }
    int solveUsingSpaceOptimised(int rows,int cols){
        vector<int>prev(cols,1);
        for(int row=1;row<rows;row++){
            vector<int>curr(cols,1);
            for(int col=1;col<cols;col++){
                curr[col]=prev[col]+curr[col-1];
            }
            prev=curr;
        }
        return prev[cols-1];
    }
    int uniquePaths(int m, int n) {
        // vector<vector<int>>grid(m,vector<int>(n,-1));
        // return solve(0,0,m,n,grid);
        // return solveUsingTab(m,n);
        return solveUsingSpaceOptimised(m,n);
    }
};