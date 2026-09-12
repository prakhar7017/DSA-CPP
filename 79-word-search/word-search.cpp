class Solution {
public:
    vector<vector<int>>directions{{-1,0},{1,0},{0,-1},{0,1}};
    bool isSafe(int idx,int x,int y,string& word,vector<vector<char>>& board){
        if(x>=0 && x<board.size() && y>=0 && y<board[0].size() && board[x][y]!='$' && word[idx]==board[x][y]) return true;
        return false;
    }
    bool solve(int idx,int currX,int currY,string&curr,string&word,vector<vector<char>>& board){
        if(idx==word.size()-1) return true;

        char temp = board[currX][currY];
        board[currX][currY]='$';

        for(vector<int>&dir:directions){
            int newX = currX + dir[0];
            int newY = currY + dir[1];

            if(isSafe(idx+1,newX,newY,word,board)){
                if(solve(idx+1,newX,newY,curr,word,board)) return true;
            }
        }
        board[currX][currY]=temp;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        string curr = "";
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if (board[i][j]==word[0]){
                    if(solve(0,i,j,curr,word,board)) return true;
                }
            }
        }
        return false;
    }
};