class Solution {
public:
    int solveUsingMemo(vector<int>& jobDifficulty,int index, int days,int jobs,vector<vector<int>>&memo){
        // base case
        if(days==1) {
            return *std::max_element(jobDifficulty.begin()+index,jobDifficulty.end());
        }

        if(memo[index][days]!=-1) return memo[index][days];
        int finalResult=INT_MAX;
        int maxD=INT_MIN;

        for(int currIdx=index;currIdx<=jobs-days;currIdx++){
            maxD=max(maxD,jobDifficulty[currIdx]);
            finalResult=min(finalResult,maxD+solveUsingMemo(jobDifficulty,currIdx+1,days-1,jobs,memo));
        }
        return memo[index][days]=finalResult;
    }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int jobs=jobDifficulty.size();
        if(jobs<d) return -1;
        vector<vector<int>>memo(jobs+1,vector<int>(d+1,-1));
        return solveUsingMemo(jobDifficulty,0,d,jobs,memo);
    }
};