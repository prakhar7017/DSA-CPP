class Solution {
public:
    int solveusingRec(int start, int end, vector<int>& cuts,
                      vector<vector<int>>& dp) {
        // basecase
        if (end - start <= 1)
            return 0;
        if (dp[start][end] != -1)
            return dp[start][end];
        int mini = INT_MAX;
        for (int partition = start + 1; partition < end; partition++) {
            int ans = (cuts[end] - cuts[start]) +
                      solveusingRec(start, partition, cuts, dp) +
                      solveusingRec(partition, end, cuts, dp);
            mini = min(ans, mini);
        }
        return dp[start][end] = mini;
    }

    int solveUsingBottomUp(int m, vector<int>& cuts) {
        sort(begin(cuts), end(cuts));
        cuts.insert(begin(cuts), 0);
        cuts.push_back(m);
        int n = cuts.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int start = n - 1; start >= 0; start--) {
            for (int end = start + 1; end < n; end++) {
                int mini = INT_MAX;

                for (int partition = start + 1; partition < end; partition++) {
                    int ans = (cuts[end] - cuts[start]) + dp[start][partition] +
                              dp[partition][end];
                    mini = min(ans, mini);
                }
                dp[start][end] = (mini == INT_MAX ? 0 : mini);
            }
        }

        return dp[0][n - 1];
    }

    int minCost(int n, vector<int>& cuts) {
        // sort(begin(cuts), end(cuts));
        // cuts.insert(begin(cuts), 0);
        // cuts.push_back(n);
        // vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        // return solveusingRec(0, cuts.size() - 1, cuts, dp);
        return solveUsingBottomUp(n, cuts);
    }
};