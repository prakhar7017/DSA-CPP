class Solution {
public:
    int solve(vector<int>& stoneValue,int index,vector<int>&dp){
        // base case
        if(index>=stoneValue.size()) return 0;
        if(dp[index]!=-1){
            return dp[index];
        }
        int ans=INT_MIN;
        int total=0;
        for(int x=1;x<=3;x++){
            if(index+x-1>=stoneValue.size()) break;
            total+=stoneValue[index+x-1];
            ans=max(ans,total-solve(stoneValue,index+x,dp));
        }
        return dp[index]=ans;
    }
    int solveTab(vector<int>& stoneValue){
        vector<int>dp(stoneValue.size()+1,0);
        for(int index=stoneValue.size()-1;index>=0;index--){
            int ans=INT_MIN;
            int total=0;
            for(int x=1;x<=3;x++){
                if(index+x-1>=stoneValue.size()) break;
                total+=stoneValue[index+x-1];
                ans=max(ans,total-solve(stoneValue,index+x,dp));
            }
            dp[index]=ans;
        }
        return dp[0];
    }
    string stoneGameIII(vector<int>& stoneValue) {
        // vector<int>dp(stoneValue.size()+1,-1);
        int ans=solveTab(stoneValue);
        if(ans<0){
            return "Bob";
        }else if(ans>0){
            return "Alice";
        }
        return "Tie";
    }
};

