class Solution {
public:
    void solve(int idx, int target, vector<int>& candidates,
               vector<int>& path, vector<vector<int>>& paths) {

        if (target == 0) {
            paths.push_back(path);
            return;
        }

        for (int i = idx; i < candidates.size(); i++) {

            // Skip duplicates at the same level
            if (i > idx && candidates[i] == candidates[i - 1])
                continue;

            // Since sorted, nothing after this can work
            if (candidates[i] > target)
                break;

            // Include
            path.push_back(candidates[i]);

            solve(i + 1, target - candidates[i],
                  candidates, path, paths);

            // Backtrack
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates,
                                        int target) {
        sort(candidates.begin(), candidates.end());

        vector<vector<int>> paths;
        vector<int> path;

        solve(0, target, candidates, path, paths);

        return paths;
    }
};