class Solution {
public:
    int rows;
    int cols;
    void dfs(vector<vector<int>>& land,int r1,int c1,int &r2,int &c2){
        // mark the land visited
        land[r1][c1]=0;
        // update r2,c2
        r2=max(r1,r2);
        c2=max(c1,c2);

        int dx[]={-1,0,1,0};
        int dy[]={0,1,0,-1};

        for(int i=0;i<4;i++){
            int newR=r1+dx[i];
            int newC=c1+dy[i];

            if(newR>=0 && newR<rows && newC>=0 && newC<cols && land[newR][newC]==1){
                dfs(land,newR,newC,r2,c2);
            }
        }
        return;
    }

    void bfs(vector<vector<int>>& land,int r1,int c1,int &r2,int &c2){
        queue<pair<int,int>>q; // stores cordinate
        // initial state
        q.push({r1,c1});

        while(!q.empty()){
            pair<int,int>p=q.front(); // taking out the pair of cordinates
            q.pop(); 
            int currX=p.first;
            int currY=p.second;
            // visting mark
            land[currX][currY]=0;
            r2=max(currX,r2);
            c2=max(currY,c2);

            int dx[]={-1,0,1,0};
            int dy[]={0,1,0,-1};

            for(int i=0;i<4;i++){
                int newR=currX+dx[i];
                int newC=currY+dy[i];

                if(newR>=0 && newR<rows && newC>=0 && newC<cols && land[newR][newC]==1){
                    land[newR][newC]=0;
                    q.push({newR,newC});
                }
            }
        }
    }

    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        rows=land.size();
        cols=land[0].size();
        vector<vector<int>>ans;

        for(int row=0;row<rows;row++){
            for(int col=0;col<cols;col++){
                if(land[row][col]==1){
                    int r1=row; // starting row
                    int c1=col; // starting col
                    int r2=row; // potential last row
                    int c2=col; // potential last col

                    bfs(land,r1,c1,r2,c2);
                    ans.push_back({r1,c1,r2,c2});
                }
            }
        }
        return ans;
    }
};