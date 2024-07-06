class Solution {
public:
    typedef pair<int,int> P;
    vector<vector<int>>directions{{-1,0},{0,1},{1,0},{0,-1}};
    bool isSafe(int x,int y,vector<vector<int>>&image){
        return x>=0 && x<image.size() && y>=0 && y<image[0].size();
    }
    void bfs(int sr,int sc, int color,map<P,bool>&vis,vector<vector<int>>&image,vector<vector<int>>&ans){
        queue<P>q;
        q.push({sr,sc});
        ans[sr][sc]=color;
        vis[{sr,sc}]=true;
        while(!q.empty()){
            P topPair=q.front();
            q.pop();
            int x=topPair.first;
            int y=topPair.second;
            for(auto dir:directions){
                int newX=x+dir[0];
                int newY=y+dir[1];

                if(isSafe(newX,newY,image) && image[newX][newY]==image[x][y] && !vis[{newX,newY}]){
                    q.push({newX,newY});
                    ans[newX][newY]=color;
                    vis[{newX,newY}]=true;
                }
            }
        }
    }
    void dfs(int sr,int sc, int color,map<P,bool>&vis,vector<vector<int>>&image,vector<vector<int>>&ans){
        vis[{sr,sc}]=true;
        ans[sr][sc]=color;
        for(auto dir:directions){
            int newX=sr+dir[0];
            int newY=sc+dir[1];

            if(isSafe(newX,newY,image) && image[newX][newY]==image[sr][sc] && !vis[{newX,newY}]){
                dfs(newX,newY,color,vis,image,ans);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>>ans=image;
        map<P,bool>vis;
        // bfs(sr,sc,color,vis,image,ans);
        dfs(sr,sc,color,vis,image,ans);
        return ans;
    }
};