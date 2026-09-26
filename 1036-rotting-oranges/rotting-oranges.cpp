class Solution {
public:
    int n;
    int m;
    typedef pair<int,int>P;
    vector<vector<int>>directions = {{-1,0},{0,1},{1,0},{0,-1}};
    bool isSafe(int x,int y,vector<vector<int>>& grid) {
        if(x>=0 && y>=0 && x<n && y<m && grid[x][y]==1) return true;
        return false;
    }
    int BFS(queue<P>&q,vector<vector<int>>& grid){
        int time = -1;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for(vector<int> &dir:directions){
                    int newX = x + dir[0];
                    int newY = y + dir[1];

                    if(isSafe(newX,newY,grid)){
                        q.push({newX,newY});
                        grid[newX][newY]=2;
                    }
                }
            }
            time++;
        }
        return time;

    }
    int orangesRotting(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int freshOrange=0;
        queue<P>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2) q.push({i,j});
                else if(grid[i][j]==1) freshOrange++;
            }
        }

        if(freshOrange == 0) return 0;

        int time = BFS(q,grid);

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1) return -1;
            }
        }

        return time;
    }
};