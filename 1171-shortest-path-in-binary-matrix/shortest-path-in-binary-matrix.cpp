class Solution {
public:
    vector<vector<int>>directions{{0,-1},{-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1}};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int rows=grid.size();
        int cols=grid[0].size();

        if(rows==0 || cols==0 || grid[0][0]==1){
            return -1;
        }

        auto isSafe=[&](int newX,int newY){
            return newX>=0 && newX<rows && newY>=0 && newY<cols;
        };

        queue<pair<int,int>>q;
        int level=0;

        q.push({0,0});
        grid[0][0]=1;

        while(!q.empty()){
            int n=q.size();
            while(n--){
                pair<int,int> frontPair=q.front();
                q.pop();
                int x=frontPair.first;
                int y=frontPair.second;

                if(x==rows-1 && y==cols-1){
                    return level+1;
                }

                for(vector<int> dir:directions){
                    int new_x=x+dir[0];
                    int new_y=y+dir[1];

                    if(isSafe(new_x,new_y) && grid[new_x][new_y]==0){
                        q.push({new_x,new_y});
                        grid[new_x][new_y]=1;
                    }
                }
            }
            level++;
        }
        return -1;
    }
};