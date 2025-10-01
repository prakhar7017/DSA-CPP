class Solution {
public:
    int solveOptimised(vector<vector<int>>& intervals){
        int n = intervals.size();
        sort(begin(intervals),end(intervals));
        int i=0;
        int j=1;
        int count=0;

        while(j<n){
            int current_start=intervals[i][0];
            int current_end=intervals[i][1];
            int next_start=intervals[j][0];
            int next_end=intervals[j][1];

            if(next_start<current_end){
                if(current_end<=next_end){
                    j++;
                    count++;
                }else{
                    i=j;
                    j++;
                    count++;
                }
            }else{
                i=j;
                j++;
            }
        }
        return count;
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        return solveOptimised(intervals);
    }
};