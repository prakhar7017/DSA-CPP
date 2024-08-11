class Solution {
public:
    int n,m;
    int dr[4]={0,0,1,-1},dc[4]={1,-1,0,0};
    void dfs(int r,int c,vector<vector<int>> &mat){
        mat[r][c]=0;
        for(int k=0;k<4;k++){
            int nr = r + dr[k],nc = c + dc[k];
            if(nr>=0 && nr<n && nc>=0 && nc<m && mat[nr][nc]==1)
                dfs(nr,nc,mat);
        }
    }
    bool isConnected(vector<vector<int>> mat){
        bool ans = false;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==1 && !ans){
                    ans=true;
                    dfs(i,j,mat);
                }
                else if(mat[i][j]==1 && ans)
                    return false;
            }
        }
        return ans;
    }
    int minDays(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        if(!isConnected(grid))
            return 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    grid[i][j]=0;
                    if(!isConnected(grid))
                        return 1;
                    grid[i][j]=1;
                }
            }
        }
        return 2;
    }
};