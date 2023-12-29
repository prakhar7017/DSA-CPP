class Solution {
    private:
    int t[301][11];
    int minDifficulty_Helper(vector<int>& jobDifficulty, int n, int index, int d) {
        // base case
        if (d == 1) {
            int maxElement = jobDifficulty[index];
            for (int i = index; i < n; i++) {
                maxElement = max(maxElement, jobDifficulty[i]);
            }
            return maxElement;
        }

        if(t[index][d]!=-1){
            return t[index][d];
        }
        // processing
        int maxD = jobDifficulty[index];
        int finalResult = INT_MAX;

        for (int i = index; i <= n - d; i++) {
            maxD = max(maxD, jobDifficulty[i]);

            // recursive 
            int result = maxD + minDifficulty_Helper(jobDifficulty, n, i + 1, d - 1);

            // update finalResult correctly
            finalResult =min(finalResult, result);
        }

        return t[index][d]=finalResult;
    }
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n=jobDifficulty.size();
        if(n<d){
            return -1;
        }

        memset(t,-1,sizeof(t));

        return minDifficulty_Helper(jobDifficulty,n,0,d);
    }
};

// Time Complexity: O(n^2 * d) 
// Space Complexity: O(n * d)

// steps to remember:

// jobs dependent hai
// atleast 1 task for each day
// difficuty of day = max(difficulty of job in that day)


