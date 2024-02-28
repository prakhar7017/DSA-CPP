class Solution {
public:
    int solve(vector<int>& sat,int i,int time,vector<vector<int>>&dp){
        // basecase
        if(i>=sat.size()){
            return 0;
        }
        if(dp[i][time]!=-1){ 
            dp[i][time];
        }
        int ans=INT_MIN;
        int includeDish=time * sat[i] + solve(sat,i+1,time+1,dp);
        int excludeDish=0+solve(sat,i+1,time,dp);
        ans=max(includeDish,excludeDish);
        return dp[i][time]=ans;
    }
    int solveTab(vector<int>& sat){
        vector<vector<int>>dp(sat.size()+1,
                                                    vector<int>(sat.size()+2,0));
        sort(begin(sat),end(sat));
        for(int i=sat.size()-1;i>=0;i--){
            for(int time=sat.size();time>=1;time--){
                int ans=INT_MIN;
                int includeDish=time * sat[i] + dp[i+1][time+1];//solve(sat,i+1,time+1,dp);
                int excludeDish=0+dp[i+1][time];//solve(sat,i+1,time,dp);
                ans=max(includeDish,excludeDish);
                dp[i][time]=ans;
            }
        }
        return dp[0][1];
    }
    int spaceOptimised(vector<int>& sat){
        int n=sat.size();
        sort(begin(sat),end(sat));
        vector<int>currRow(n+2,0);
        vector<int>nextRow(n+2,0);
        for(int i=sat.size()-1;i>=0;i--){
            for(int time=sat.size();time>=1;time--){
                int ans=INT_MIN;
                int includeDish=time * sat[i] + nextRow[time+1];//solve(sat,i+1,time+1,dp);
                int excludeDish=0+nextRow[time];//solve(sat,i+1,time,dp);
                ans=max(includeDish,excludeDish);
                currRow[time]=ans;
            }
            //shifting
            nextRow=currRow;
        }
        return nextRow[0];
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        // vector<vector<int>>dp(satisfaction.size()+1,
        //                                             vector<int>(satisfaction.size()+1,-1));
        // int time=1;
        // sort(begin(satisfaction),end(satisfaction));
        return solveTab(satisfaction);
    }
};

// time complexity is O(nlogn) 
// space complexity is O(n)
