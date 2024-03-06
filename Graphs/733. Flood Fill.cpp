class Solution {
public:
    bool isSafe(int newX,int newY,int currX,int currY,map<pair<int,int>,bool>&vis,vector<vector<int>>& image){
        if(newX >= 0 && newY >= 0 && newX < image.size() && newY < image[0].size() && image[newX][newY]==image[currX][currY] && !vis[{newX,newY}]){
            return true;
        }
        return false;
    }
    void dfs(int sr,int sc,int color,map<pair<int,int>,bool>&vis,vector<vector<int>>& image,vector<vector<int>>&ans){
        vis[{sr,sc}]=true;
        ans[sr][sc]=color;
        int dx[]={-1,0,1,0};
        int dy[]={0,1,0,-1};
        for(int i=0;i<4;i++){
            int newX=sr+dx[i];
            int newY=sc+dy[i];
            if(isSafe(newX,newY,sr,sc,vis,image)){
                dfs(newX,newY,color,vis,image,ans);
            }
        }

    }
    void bfs(int sr,int sc,int color,map<pair<int,int>,bool>&vis,vector<vector<int>>& image,vector<vector<int>>&ans){
        queue<pair<int,int>>q;
        
        // initial State
        q.push({sr,sc});
        vis[{sr,sc}]=true;
        ans[sr][sc]=color;

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
                if(isSafe(newX,newY,currX,currY,vis,image)){
                    q.push({newX,newY});
                    vis[{newX,newY}]=true;
                    ans[newX][newY]=color;
                }
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>>ans=image;
        if(image[sr][sc]==color) return ans;

        map<pair<int,int>,bool>vis;
        // bfs(sr,sc,color,vis,image,ans);
        dfs(sr,sc,color,vis,image,ans);
        return ans;

    }
};