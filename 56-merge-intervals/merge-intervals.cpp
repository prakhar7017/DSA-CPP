class Solution {
public:
    vector<vector<int>> solveUsingBruteForce(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>> ans;
        vector<bool> vis(n, false);
        for (int i = 0; i < n; i++) {
            if (vis[i])
                continue;
            int currStart = intervals[i][0];
            int currEnd = intervals[i][1];
            vis[i] = true;
            bool merged = true;
            while (merged) {
                merged = false;
                for (int j = 0; j < n; j++) {
                    if (vis[j])
                        continue;
                    int nextStart = intervals[j][0];
                    int nextEnd = intervals[j][1];
                    if (nextStart <= currEnd && nextEnd >= currStart) {
                        currStart = min(currStart, nextStart);
                        currEnd = max(currEnd, nextEnd);
                        vis[j] = true;
                        merged = true;
                    }
                }
            }
            ans.push_back({currStart, currEnd});
        }
        return ans;
    }
    vector<vector<int>> solveUsingOptimised(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(begin(intervals), end(intervals));
        vector<vector<int>>  ans;
        ans.push_back(intervals[0]);

        for(int i=1;i<n;i++){
            int currStart = intervals[i][0];
            int currEnd   = intervals[i][1];
            if(currStart<=ans.back()[1]){
                ans.back()[1] = max(currEnd,ans.back()[1]);
            }else{
                ans.push_back({currStart,currEnd});
            }
        }
        return ans;
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        return solveUsingOptimised(intervals);
    }
};