class Solution
{
public:
    bool isSafe(int row,int col,vector<vector<int>> &mat){
        if(mat[row][col]==0) return false;
        else if(row-1>=0 && mat[row-1][col]==0) return false; //up
        else if(col+1<mat[0].size() &&  mat[row][col+1]==0) return false; // right
        else if(row+1<mat.size() &&  mat[row+1][col]==0) return false; // down
        else if(col-1>=0 && mat[row][col-1]==0) return false; // left
        return true;
    }
    
    int solve(int row, int col, vector<vector<int>>& mat, vector<vector<bool>>& vis) {
        if (col == mat[0].size() - 1) return 1;
        vis[row][col] = true;

        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};
        int ans = 1e9;

        for (int i = 0; i < 4; i++) {
            int newX = row + dx[i];
            int newY = col + dy[i];
             if(newX>=0 && newX<mat.size() && newY>=0 
            && newY<mat[0].size() && isSafe(newX,newY,mat) && !vis[newX][newY]){
                int include = 1 + solve(newX, newY, mat, vis);
                ans = min(ans, include);
            }
        }
        vis[row][col] = false;
        return ans;
    }

    int findShortestPath(vector<vector<int>> &mat)
    {
        int rows=mat.size();
        int cols=mat[0].size();
        vector<vector<bool>>vis(rows,vector<bool>(cols,false));
        int ans=1e9;
        for(int row=0;row<rows;row++){
            int col=0;
            if(isSafe(row,col,mat)){
                ans=min(ans,solve(row,col,mat,vis));
            }
        }
        return ans==1e9 ? -1 : ans;
    }
};

// time complexity: O(4^(n*m))
// space complexity: O(n*m) + O(n*m) + O(1) = O(n*m)