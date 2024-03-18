
// Brute Force 
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int i=0;
        while(i<intervals.size()){
            if(intervals[i][1]<newInterval[0]) ++i;
            else if(intervals[i][0]>newInterval[1]){
                intervals.insert(intervals.begin()+i,newInterval);
                return intervals;
            }else {
                newInterval[0]=min(intervals[i][0],newInterval[0]);
                newInterval[1]=max(intervals[i][1],newInterval[1]);
                intervals.erase(intervals.begin()+i);

            }
        }
        intervals.push_back(newInterval);
        return intervals;
    }
};

// time complexity: O(n)
// space complexity: O(1)

//-------------------------------------------------------------------------------

// Optimal
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int i=0;
        vector<vector<int>>ans;
        while(i<intervals.size()){
            if(intervals[i][1]<newInterval[0]){ // interval ka ending point kam hh, toh peche ayega newInterval ke
                ans.push_back(intervals[i]);
            }
            else if(intervals[i][0]>newInterval[1]){ // interval ka starting point zyada hh, toh aage ayega newInterval ke
                break;
            }else { // interval and newInterval overlap krte hh
                newInterval[0]=min(intervals[i][0],newInterval[0]);
                newInterval[1]=max(intervals[i][1],newInterval[1]);
            }
            ++i;
        }
        // after coming out of loop due to break;
        ans.push_back(newInterval); // first insert newInterval
        while(i<intervals.size()){
            ans.push_back(intervals[i]); // then insert remaining intervals
            ++i;
        }
        return ans;
    }
};