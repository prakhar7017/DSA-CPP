class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(begin(intervals),end(intervals));
        vector<vector<int>>ans;
        ans.push_back(intervals[0]);
        for(int i=1;i<n;i++){
            int currStart = intervals[i][0];
            int currEnd   = intervals[i][1];

            if(currStart<=ans.back()[1]){
                ans.back()[1]=max(ans.back()[1],currEnd);
            }else{
                ans.push_back({currStart,currEnd});
            }
        }
        return ans;
    }
};