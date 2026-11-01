class Solution {
public:
    vector<vector<int>> solveUsingBruteForce(vector<vector<int>>& intervals){
        int n = intervals.size();
        vector<bool>vis(n,false);
        vector<vector<int>>result;
        for(int i=0;i<n;i++){
            if(vis[i]) continue;

            int currStart = intervals[i][0];
            int currEnd   = intervals[i][1];
            vis[i]=true;
            bool merged = true;

            while(merged){
                merged = false;
                for(int j=0;j<n;j++){
                    if(vis[j]) continue;
                    int nextStart = intervals[j][0];
                    int nextEnd   = intervals[j][1];

                    if(nextStart<=currEnd && nextEnd>=currStart){
                        currStart = min(currStart,nextStart);
                        currEnd   = max(currEnd,nextEnd);
                        vis[j]=true;
                        merged = true;
                    }
                }
            }
            result.push_back({currStart,currEnd});
        }
        return result;
    } 
    vector<vector<int>> optimal(vector<vector<int>>& intervals){
        int n = intervals.size();
        sort(begin(intervals),end(intervals));
        vector<vector<int>> result;
        result.push_back(intervals[0]);

        for(int i=1;i<n;i++){
            int currStart = intervals[i][0];
            int currEnd   = intervals[i][1];
            if(currStart<=result.back()[1]){
                result.back()[1]= max(currEnd,result.back()[1]);
            }else{
                result.push_back(intervals[i]);
            }
        }
        return result;
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        return optimal(intervals);
    }
};