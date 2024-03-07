
// bfs Approach
class Solution {
public:

    bool isSafe(int newX,int newY,int currX,int currY,vector<vector<int>>& temp){
        if(newX>=0 && newY>=0 && newX <temp.size() && newY<temp[0].size() && temp[newX][newY]==1){
            return true;
        }
        return false;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        vector<vector<int>>temp=grid;
        int minTime=0;
        queue<pair<pair<int,int>,int>>q;

        // putting all rotten oragnes at time=0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                }
            }
        }

        while(!q.empty()){
            pair<pair<int,int>,int>frontNodePair=q.front();
            q.pop();
            pair<int,int>frontNodeCor=frontNodePair.first;
            int frontNodeTime=frontNodePair.second;
            int currX=frontNodeCor.first;
            int currY=frontNodeCor.second;

            int dx[]={-1,0,1,0};
            int dy[]={0,1,0,-1};

            for(int i=0;i<4;i++){
                int newX=currX+dx[i];
                int newY=currY+dy[i];

                if(isSafe(newX,newY,currX,currY,temp)){
                    q.push({{newX,newY},frontNodeTime+1});
                    minTime=max(minTime,frontNodeTime+1);
                    temp[newX][newY]=2;
                }
            }
        }
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(temp[i][j]==1){
                    return -1;
                }
            }
        }
        return minTime;
        
    }
};
// time complexity:O(n*m)
// space complexity:O(n*m)








// dfs Approach 
class Solution {
public:
    bool isSafe(int newX,int newY,int srcX,int srcY,map<pair<int,int>,bool>&vis,vector<vector<int>>& grid,vector<vector<int>>&temp){
        if(newX >= 0 && newY >= 0 && newX < grid.size() && newY<grid[0].size() && grid[newX][newY]==1 && temp[newX][newY]==1 &&  !vis[{newX,newY}]){
            return true;
        }
        return false;
    }
    int dfs(int srcX,int srcY,int time,map<pair<int,int>,bool>&vis,vector<vector<int>>& grid,vector<vector<int>>& temp){
        vis[{srcX,srcY}]=true;
        int dx[]={-1,0,1,0};
        int dy[]={0,1,0,-1};
        int minTime=0;
        for(int i=0;i<4;i++){
            int newX=srcX+dx[i];
            int newY=srcY+dy[i];
            if(isSafe(newX,newY,srcX,srcY,vis,grid,temp)){
                temp[newX][newY]=2;
                minTime=max(minTime,dfs(newX,newY,time+1,vis,grid,temp));
            }
        }
        return max(time,minTime);
    }
    int orangesRotting(vector<vector<int>>& grid) {
        map<pair<int,int>,bool>vis;
        vector<vector<int>>temp=grid;
        int row=grid.size();
        int col=grid[0].size();
        int time=0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(!vis[{i,j}] && grid[i][j]==2){
                    time=dfs(i,j,time,vis,grid,temp);
                }
            }
        }
         for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(temp[i][j]==1){
                   return -1;
                }
            }
        }
        
        return time;
    }
};
// to be analysed 