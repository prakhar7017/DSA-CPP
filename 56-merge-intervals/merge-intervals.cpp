class Solution {
public:
    vector<vector<int>> solveBruteForce(vector<vector<int>>& intervals){
        int n= intervals.size();
        sort(begin(intervals),end(intervals));
        vector<vector<int>>ans;
        for(int i=0;i<n;i++){
            int current_start=intervals[i][0];
            int current_end=intervals[i][1];
            if(!ans.empty() && current_end<=ans.back()[1]) continue;
            for(int j=i+1;j<n;j++){
                int next_start=intervals[j][0];
                int next_end=intervals[j][1];
                if(next_start<=current_end){
                    current_end = max(current_end,next_end);
                }else{
                    break;
                }
            }
            ans.push_back({current_start,current_end});
        }
        return ans;
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        return solveBruteForce(intervals);
    }
};