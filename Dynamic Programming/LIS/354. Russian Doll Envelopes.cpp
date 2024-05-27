// Pattern LIS

class Solution {
public:
    bool check(vector<int> &a ,vector<int>&b){
        if(a[0]<b[0] && a[1]<b[1]){
            return true;
        }
        return false;
    }
    int solveRec(vector<vector<int>>& env,int prev,int curr,vector<vector<int>>&dp){
        //base case
        if(curr>=env.size()){
            return 0;
        }
        if(dp[prev+1][curr]!=-1){
            return dp[prev+1][curr];
        }

        int include=INT_MIN;
        if(prev==-1 || check(env[prev],env[curr])){
            include=1+solveRec(env,curr,curr+1,dp);
        }
        int exclude=0+solveRec(env,prev,curr+1,dp);
        return dp[prev+1][curr]=max(include,exclude);
    }
    int solveTab(vector<vector<int>>& env){
        int n=env.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        for(int curr=n-1;curr>=0;curr--){
            for(int prev=curr-1;prev>=-1;prev--){
                int include=INT_MIN;
                if(prev==-1 || check(env[prev],env[curr])){
                    include=1+ dp[curr+1][curr+1]; //dp[curr+1][curr+1];
                }
                int exclude=0+dp[curr+1][prev+1]; //dp[prev+1][curr+1];
                dp[curr][prev+1]=max(include,exclude);
            }
        }
        return dp[0][0];
    }
    int spaceOptimized(vector<vector<int>>& env){
        int n=env.size();
        vector<int>currRow(n+1,0);
        vector<int>nextRow(n+1,0);
        for(int curr=n-1;curr>=0;curr--){
            for(int prev=curr-1;prev>=-1;prev--){
                int include=INT_MIN;
                if(prev==-1 || check(env[prev],env[curr])){
                    include=1+nextRow[curr+1];
                }
                int exclude=0+nextRow[prev+1];
                currRow[prev+1]=max(include,exclude);
            }
            // shifting
            nextRow=currRow;
        }
        return nextRow[0];
        
    }
    static bool comp(vector<int>a,vector<int>b){
        if(a[0]==b[0]){
            return a[1]>b[1];
        }
        return a[0]<b[0];
    }
    int solveOptimal(vector<vector<int>>& env){
        sort(env.begin(),env.end(),comp);

        if(env.size()==0){
            return 0;
        }
        vector<int>ans;
        ans.push_back(env[0][1]);
        for(int i=1;i<env.size();i++){
            if(env[i][1]>ans.back()){
                ans.push_back(env[i][1]);
            }else{
                // just bada exist
                int index=lower_bound(ans.begin(),ans.end(),env[i][1])-ans.begin();
                ans[index]=env[i][1];
            }
        }
        return ans.size();
    }

    int maxEnvelopes(vector<vector<int>>& envelopes) {
        // sort(envelopes.begin(),envelopes.end());
        // int prev=-1;
        // int curr=0;
        // vector<vector<int>>dp(envelopes.size()+1,vector<int>(envelopes.size()+1,-1));
        return solveOptimal(envelopes);
    }
};