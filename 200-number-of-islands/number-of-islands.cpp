class Solution {
public:
    vector<vector<int>>directions={{0,1},{1,0},{0,-1},{-1,0}};
    bool isSafe(int i,int j,vector<vector<bool>>&vis,vector<vector<char>>& grid){
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || vis[i][j] || grid[i][j]=='0' )return false;
        return true;
    }
    void DFS(int i,int j,vector<vector<bool>>&vis,vector<vector<char>>& grid){
        vis[i][j]=true;

        for(vector<int>dir:directions){
            int newX = i + dir[0];
            int newY = j + dir[1];

            if(isSafe(newX,newY,vis,grid)){
                DFS(newX,newY,vis,grid);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>>vis(m,vector<bool>(n,false));
        int count =0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == '1' && !vis[i][j]){
                    DFS(i,j,vis,grid);
                    count++;
                }
            }
        }
        return count;
    }
};