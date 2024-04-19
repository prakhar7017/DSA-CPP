class Solution {
public:
    bool isSafe(int newX,int newY,int currX,int currY,map<pair<int,int>,bool>&vis,vector<vector<char>>& grid){
        if(newX >=0 && newX < grid.size() && newY>=0 && newY < grid[0].size() && grid[newX][newY]=='1' 
        && !vis[{newX,newY}]){
            return true;
        }
        return false;
    }
    void bfs(int srcX,int srcY,map<pair<int,int>,bool>&vis,vector<vector<char>>& grid){
        queue<pair<int,int>>q;

        // inital State
        q.push({srcX,srcY});
        vis[{srcX,srcY}]=true;

        while(!q.empty()){
            pair<int,int>topPair=q.front();
            q.pop();
            int currX=topPair.first;
            int currY=topPair.second;

            int dx[]={-1,0,1,0};
            int dy[]={0,1,0,-1};

            for(int i=0;i<4;i++){
                int newX=currX+dx[i];
                int newY=currY+dy[i];
                if(isSafe(newX,newY,currX,currY,vis,grid)){
                    q.push({newX,newY});
                    vis[{newX,newY}]=true;
                }
            }

        }
    }
    int numIslands(vector<vector<char>>& grid) {
        map<pair<int,int>,bool>vis;
        int row=grid.size();
        int col=grid[0].size();
        int count=0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(!vis[{i,j}] && grid[i][j]=='1'){
                    bfs(i,j,vis,grid);
                    count++;
                }
            }
        }
        return count;
    }
};