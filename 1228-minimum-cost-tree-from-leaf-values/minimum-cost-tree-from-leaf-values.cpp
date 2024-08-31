class Solution {
public:
    int solve(vector<int>& arr,int start,int end,map<pair<int,int>,int>&maxi,vector<vector<int>>&dp){
        if(start>end){
            return 0;
        }
        if(start==end){
            return 0;
        }
        if(dp[start][end]!=-1){
            return dp[start][end];
        }
        int ans=INT_MAX;
        for(int i=start;i<end;i++){
            // i is used for partitiioning
            ans=min(ans,(maxi[{start,i}]*maxi[{i+1,end}])
            +
                solve(arr,start,i,maxi,dp)+
                solve(arr,i+1,end,maxi,dp)
            );
        }
        return dp[start][end]=ans;
    }
    int mctFromLeafValues(vector<int>& arr) {
        vector<vector<int>>dp(arr.size(),vector<int>(arr.size(),-1));
        map<pair<int,int>,int>maxi;
        for(int i=0;i<arr.size();i++){
            maxi[{i,i}]=arr[i];
            for(int j=i+1;j<arr.size();j++){
                maxi[{i,j}]=max(arr[j],maxi[{i,j-1}]);
            }
        }
        int start=0;
        int end=arr.size()-1;
        return solve(arr,start,end,maxi,dp);
    }
};