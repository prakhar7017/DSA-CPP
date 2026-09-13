class Solution {
public:
    vector<vector<string>> ans;
    int N;
    bool isSafe(int row, int col, vector<string>& board) {
        // Same column
        for (int i = row - 1; i >= 0; i--) {
            if (board[i][col] == 'Q')
                return false;
        }

        // Upper-left diagonal
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q')
                return false;
        }

        // Upper-right diagonal
        for (int i = row - 1, j = col + 1; i >= 0 && j < N; i--, j++) {
            if (board[i][j] == 'Q')
                return false;
        }

        return true;
    }
    void solve(int row, vector<string>& board) {
        if (row >= N) {
            ans.push_back(board);
            return;
        }
        for (int col = 0; col < N; col++) {
            if (isSafe(row, col, board)) {
                board[row][col] = 'Q';
                solve(row + 1, board);
                board[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        N = n;
        vector<string> board(n, string(n, '.'));
        solve(0, board);
        return ans;
    }
};