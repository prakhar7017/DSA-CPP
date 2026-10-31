class Solution {
public:
    typedef pair<int,int>P;
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
    void BFS(int i,int j,vector<vector<bool>>&vis,vector<vector<char>>& grid){
        queue<P>q;
        q.push({i,j});
        vis[i][j]=true;
        while(!q.empty()){
            int currX = q.front().first;
            int currY = q.front().second;
            q.pop();

            for(vector<int>dir:directions){
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
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>>vis(m,vector<bool>(n,false));
        int count =0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == '1' && !vis[i][j]){
                    BFS(i,j,vis,grid);
                    count++;
                }
            }
        }
        return count;
    }
};