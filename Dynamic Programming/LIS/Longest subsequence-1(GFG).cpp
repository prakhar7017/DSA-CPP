/*
    Longest subsequence-1
    Given an integer array a[] of size n, find the length of the longest subsequence such that the absolute difference between adjacent elements is 1.

*/


class Solution {
  public:
    int solveLIS(vector<int>&a,int prev,int curr){
        // base case
        if(curr>=a.size()) return 0;
        int include=0;
        if(prev==-1 || abs(a[curr]-a[prev])==1)
            include=1+solveLIS(a,curr,curr+1);
        int exclude=0+solveLIS(a,prev,curr+1);
        
        return max(include,exclude);
    }
    int solveLISMEMO(vector<int>&a,int prev,int curr,vector<vector<int>>&dp){
        // base case
        if(curr>=a.size()) return 0;
        if(dp[curr][prev+1]!=-1){
            return dp[curr][prev+1];
        }
        int include=0;
        if(prev==-1 || abs(a[curr]-a[prev])==1)
            include=1+solveLISMEMO(a,curr,curr+1,dp);
        int exclude=0+solveLISMEMO(a,prev,curr+1,dp);
        
        return dp[curr][prev+1]=max(include,exclude);
    }
    int solveLISTAB(vector<int>&a){
        int len=a.size();
        vector<vector<int>>dp(len+1,vector<int>(len+1,0));
        for(int curr=len-1;curr>=0;--curr){
            for(int prev=curr-1;prev>=-1;--prev){
                int include=0;
                if(prev==-1 || abs(a[curr]-a[prev])==1)
                    include=1+dp[curr+1][curr+1];
                int exclude=0+dp[curr+1][prev+1];
                dp[curr][prev+1]=max(include,exclude);
            }
        }
        return dp[0][0];
    }
    int solveLISSpace(vector<int>&a){
        int len=a.size();
        vector<int>nextRow(len+1);
        vector<int>currRow(len+1);
        for(int curr=len-1;curr>=0;--curr){
            for(int prev=curr-1;prev>=-1;--prev){
                int include=0;
                if(prev==-1 || abs(a[curr]-a[prev])==1)
                    include=1+nextRow[curr+1];
                int exclude=0+nextRow[prev+1];
                currRow[prev+1]=max(include,exclude);
            }
            // shifting
            nextRow=currRow;
        }
        return nextRow[0];
    }
    
    
    
    int longestSubseq(int n, vector<int> &a) {
        int len=a.size();
        int curr=0;
        int prev=-1;
        // return solveLIS(a,prev,curr);
        vector<vector<int>>dp(len+1,vector<int>(len+1,-1));
        // return solveLISMEMO(a,prev,curr,dp);
        return solveLISSpace(a);
    }
};