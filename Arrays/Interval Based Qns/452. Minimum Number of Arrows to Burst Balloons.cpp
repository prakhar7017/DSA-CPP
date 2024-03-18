class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(begin(points),end(points));
        int n=points.size();
        int count=1;
        vector<int> prev=points[0];

        for(int i=1;i<n;i++){
            int currStartingPoint=points[i][0];
            int currEndingPoint=points[i][1];
            int prevStartingPoint=prev[0];
            int prevEndingPoint=prev[1];
            if(currStartingPoint>prevEndingPoint){ // no overlap
                ++count; // curr balloon ko burst karne ke lye one arrow more
                prev=points[i];
            }else{ // overlap
                // no need of one more arrow
                // find overlapping range
                prev[0]=max(prevStartingPoint,currStartingPoint);
                prev[1]=min(prevEndingPoint,currEndingPoint);
            }
        }
        return count;
    }
};

time complexity : o(nlogn)
space complexity: o(1)