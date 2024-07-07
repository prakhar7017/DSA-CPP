class Solution {
public:
    typedef pair<int,int> P;

    bool isSafe(int x, int y, vector<vector<int>>& grid) {
        return x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size();
    }

    vector<vector<int>> directions{{-1,0},{0,1},{1,0},{0,-1}};

    int bfs(queue<P>& q, vector<vector<int>>& grid) {
        int time = -1; // Initialize to -1 because the last increment happens after the last spread

        while (!q.empty()) {
            int n = q.size();
            while (n--) {
                P frontPair = q.front();
                q.pop();
                int x = frontPair.first;
                int y = frontPair.second;

                for (auto dir : directions) {
                    int newX = x + dir[0];
                    int newY = y + dir[1];

                    if (isSafe(newX, newY, grid) && (grid[newX][newY] == 1)) {
                        q.push({newX, newY});
                        grid[newX][newY] = 2;
                    }
                }
            }
            time++;
        }

        return time;
    }

    int orangesRotting(vector<vector<int>>& grid) {
        queue<P> q;
        int rows = grid.size();
        int cols = grid[0].size();
        int freshOranges = 0;

        // Put all rotten oranges into queue and count fresh oranges
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (grid[row][col] == 2) {
                    q.push({row, col});
                } else if (grid[row][col] == 1) {
                    freshOranges++;
                }
            }
        }

        // If there are no fresh oranges, return 0
        if (freshOranges == 0) return 0;

        int time = bfs(q, grid);

        // After BFS, check if there are any fresh oranges left
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (grid[row][col] == 1) {
                    return -1;
                }
            }
        }

        return time;
    }
};
