class Solution {
public:
    typedef pair<int,pair<int,int>>P;
    int n;
    vector<vector<int>>directions={{-1,0},{0,1},{1,0},{0,-1}};
    bool isSafe(int x,int y, int time,vector<vector<int>>&vis,vector<vector<int>>& grid){
        if(x>=0 && x<n && y>=0 && y<n && !vis[x][y] && grid[x][y]<=time) return true;
        return false;
    }
    bool isPossible(int i,int j,int time,vector<vector<int>>&vis,vector<vector<int>>& grid){
        if(i<0 || i>=n || j<0 || j>=n || vis[i][j] || grid[i][j]>time) return false;

        vis[i][j]=1;

        if(i == n-1 && j==n-1) return true;

        for(vector<int>&dir:directions){
            int new_i = i + dir[0];
            int new_j = j + dir[1];
            if(isSafe(new_i,new_j,time,vis,grid)){
                if(isPossible(new_i,new_j,time,vis,grid)) return true;
            }
        }
        return false;
    }
    int DJ(vector<vector<int>>& grid){
        int n = grid.size();
        vector<vector<int>>result(n,vector<int>(n,INT_MAX));
        priority_queue<P,vector<P>,greater<P>>pq;
        result[0][0]=grid[0][0];
        pq.push({grid[0][0],{0,0}});

        while(!pq.empty()){
            int currTime = pq.top().first;
            int i        = pq.top().second.first;
            int j        = pq.top().second.second;
            pq.pop();

            if(i == n-1 && j==n-1) return currTime;

            if(currTime>result[i][j]) continue;

            for(vector<int>&dir:directions){
                int newX = i + dir[0];
                int newY = j + dir[1];

                if(newX>=0 && newY>=0 && newX<n && newY<n){
                    int nextTime = max(currTime,grid[newX][newY]);
                    if(nextTime<result[newX][newY]){
                        result[newX][newY]=nextTime;
                        pq.push({nextTime,{newX,newY}});
                    }
                }
            }
        }
        return -1;
    }
    int swimInWater(vector<vector<int>>& grid) {
        return DJ(grid);
        // n = grid.size();
        // int l =grid[0][0];
        // int r = n*n-1;
        // int ans = 0;
        // while(l<=r){
        //     int mid = l+(r-l)/2;
        //     vector<vector<int>>vis(n,vector<int>(n,0));
        //     if(isPossible(0,0,mid,vis,grid)){
        //         ans = mid;
        //         r = mid-1;
        //     }else{
        //         l = mid+1;
        //     }
        // }
        // return ans;
    }
};