class Solution {
public:
    int m;
    int n;
    void solve(vector<vector<int>>& matrix) {
        // transpose
        for (int i = 0; i < m; i++) {
            for (int j = i; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        // revere
        for (int i = 0; i < m; i++) {
            reverse(begin(matrix[i]), end(matrix[i]));
        }
    }
    void rotate(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        solve(matrix);
    }
};