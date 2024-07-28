class Solution {
private:
    int bfs(int n, vector<vector<int>> &adjList, int source){
        vector<int> shortest1(n, INT_MAX);
        vector<int> shortest2(n, INT_MAX);

        queue<pair<int, int>> q;
        q.push({source, 0});

        while(!q.empty()){
            auto [u, dist] = q.front(); // First In First Out 
            q.pop();

            for(auto &nei : adjList[u]){
                int currDist = dist + 1;
                if(shortest1[nei] > currDist){
                    shortest2[nei] = shortest1[nei];
                    shortest1[nei] = currDist;
                    q.push({nei, currDist});
                }
                else if(shortest1[nei] < currDist && currDist < shortest2[nei]){
                    shortest2[nei] = currDist;
                    q.push({nei, currDist});
                }
            }

        }
        return shortest2[n - 1] == INT_MAX ? - 1 : shortest2[n - 1];
    }
    int binarySearch(int low, int high, int val, int change){
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(mid * change > val) high = mid - 1;
            else low = mid + 1;
        }
        return low - 1;
    }
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        // Assumption there is an ege from 2 - 5
        // 1 - 2 - 5 - x - 2
        // 1 - 4 - 5 - x - 2
        // 1 - 3 - 4 - 5 - x + t - 3
        // 1 - 3 - 4 - 3 - 5 - x + t + d - 4
        // hop count is directly propotional to the time taken
        vector<vector<int>> adjList(n, vector<int> {});
        // 1 - {}
        // 2 - {}
        // 3 - {}
        // 4 - {}
        // 5 - {}
        for(auto &edge : edges){
            int u = edge[0] - 1;
            int v = edge[1] - 1;
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        int hopCount = bfs(n, adjList, 0);
        // 0 - 5 --> green // 5  * (0 -> 1)
        // 5 - 10 --> red // 5 * (1 -> 2)
        // 10 - 15 --> green // 6 * (2 -> 3)
        // 15 - 20 --> red
        // 20 - 16 --> 4
        // value and change 5 
        // 6
        // 23
        // 6 * 3 = 18 && 6 * 4 = 24
        // 3
        int low  = 0;
        int high = 1e5;
        int val = 0;
        while(hopCount--){
            int bs = binarySearch(low, high, val, change);
            if(bs % 2 != 0){
                int waitingTime = (change * (bs + 1)) - val;
                val += waitingTime;
            }
            val += time;
        }
        return val;
    }
};