class Solution {
public:
    int N;
    vector<vector<string>> result;
    unordered_set<int> cols;
    unordered_set<int> diags;
    unordered_set<int> antidiags;
    bool isValid(int row, int col, vector<string>& board) {
        // upward
        for (int i = row - 1; i >= 0; i--) {
            if (board[i][col] == 'Q')
                return false;
        }
        // right diagonal
        for (int i = row - 1, j = col + 1; i >= 0 && j < N; i--, j++) {
            if (board[i][j] == 'Q')
                return false;
        }
        // left diagonal
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q')
                return false;
        }
        return true;
    }
    void solve(int row, vector<string>& board) {
        if (row >= N) {
            result.push_back(board);
            return;
        }
        for (int col = 0; col < N; col++) {
            int diag = row + col;
            int antidiag = row - col;
            if (cols.find(col) != cols.end() ||
                diags.find(diag) != diags.end() ||
                antidiags.find(antidiag) != antidiags.end())
                continue;
            cols.insert(col);
            diags.insert(diag);
            antidiags.insert(antidiag);    
            board[row][col] = 'Q';

            solve(row + 1, board);
            
            cols.erase(col);
            diags.erase(diag);
            antidiags.erase(antidiag); 
            board[row][col] = '.';
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        N = n;
        vector<string> board(n, string(n, '.'));
        solve(0, board);
        return result;
    }
};