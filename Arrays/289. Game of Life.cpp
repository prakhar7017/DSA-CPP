class Solution {
    private:
    bool validCordinate(vector<vector<int>>& board,int x ,int y){
        return (x>=0 && x<board.size() && y>=0 && y<board[0].size());
    }
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<int> dx={0,0,1,1,1,-1,-1,-1};
        vector<int> dy={1,-1,1,-1,0,0,1,-1};

        int row=board.size();
        int col=board[0].size();

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                int live_count=0;
                for(int k=0;k<8;k++){
                    int x=i+dx[k];
                    int y=j+dy[k];
                    if(validCordinate(board,x,y) && abs(board[x][y])==1){
                        live_count++;
                    }
                }
                if(board[i][j]==1 && (live_count < 2 || live_count >3 )){
                    board[i][j]=-1;
                }
                if(board[i][j]==0 && live_count==3){
                    board[i][j]=2;
                }
            }
        }
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(board[i][j]>=1){
                    board[i][j]=1;
                }else{
                    board[i][j]=0;
                }
            }
        }
    }
};