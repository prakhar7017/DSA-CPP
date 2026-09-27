class Solution {
public:
    int n;
    int m;

    vector<vector<int>> directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    bool BruteDFS(int i, int j, vector<vector<int>>& vis,
                  vector<vector<int>>& heights, bool pacific) {

        if (pacific && (i == 0 || j == 0))
            return true;

        if (!pacific && (i == n - 1 || j == m - 1))
            return true;

        vis[i][j] = true;

        for (auto& dir : directions) {
            int i_ = i + dir[0];
            int j_ = j + dir[1];

            if (i_ >= 0 && j_ >= 0 && i_ < n && j_ < m && !vis[i_][j_] &&
                heights[i_][j_] <= heights[i][j]) {

                if (BruteDFS(i_, j_, vis, heights, pacific))
                    return true;
            }
        }

        return false;
    }

    void DFS(vector<vector<int>>& heights, int i, int j, int prevVal,
             vector<vector<bool>>& vis) {

        if (i < 0 || i >= n || j < 0 || j >= m || vis[i][j] ||
            heights[i][j] < prevVal)
            return;

        vis[i][j] = true;

        for (auto& dir : directions) {
            int i_ = i + dir[0];
            int j_ = j + dir[1];
            DFS(heights, i_, j_, heights[i][j], vis);
        }
    }

    // vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

    //     n = heights.size();
    //     m = heights[0].size();

    //     vector<vector<int>> ans;

    //     for (int i = 0; i < n; i++) {
    //         for (int j = 0; j < m; j++) {

    //             vector<vector<int>> vis1(n, vector<int>(m, false));
    //             bool canPacific = BruteDFS(i, j, vis1, heights, true);

    //             vector<vector<int>> vis2(n, vector<int>(m, false));
    //             bool canAtlantic = BruteDFS(i, j, vis2, heights, false);

    //             if (canPacific && canAtlantic) {
    //                 ans.push_back({i, j});
    //             }
    //         }
    //     }

    //     return ans;
    // }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        n = heights.size();
        m = heights[0].size();

        vector<vector<int>> ans;
        vector<vector<bool>> pacificVisited(n, vector<bool>(m, false));
        vector<vector<bool>> atlanticVisited(n, vector<bool>(m, false));

        for (int j = 0; j < m; j++) {
            DFS(heights, 0, j, INT_MIN, pacificVisited);
            DFS(heights, n - 1, j, INT_MIN, atlanticVisited);
        }
        for (int i = 0; i < n; i++) {
            DFS(heights, i, 0, INT_MIN, pacificVisited);
            DFS(heights, i, m - 1, INT_MIN, atlanticVisited);
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (pacificVisited[i][j] && atlanticVisited[i][j])
                    ans.push_back({i, j});
            }
        }
        return ans;
    }
};