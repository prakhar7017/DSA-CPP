class Solution {
public:
    int CountSteps(int ringIdx,int elementIdx, int ringLen){
        int distance=abs(elementIdx-ringIdx);
        int wrapAround=abs(ringLen-distance);
        return min(distance,wrapAround);
    }
    int solve(int ringIdx,int keyIdx,string &ring,string &key,vector<vector<int>>&dp){
        // base case
        if(keyIdx==key.length()) return 0;
        if(dp[ringIdx][keyIdx]!=-1){
            return dp[ringIdx][keyIdx];
        }
        int result=INT_MAX;
        for(int i=0;i<ring.length();i++){
            if(ring[i]==key[keyIdx]){
                int totalSteps=CountSteps(ringIdx,i,ring.length()) + 1 + solve(i,keyIdx+1,ring,key,dp);
                result=min(result,totalSteps);
            }
        }
        return dp[ringIdx][keyIdx]=result;
    }
    int findRotateSteps(string ring, string key) {
        vector<vector<int>>dp(ring.length(),vector<int>(key.length(),-1));
        return solve(0,0,ring,key,dp);
    }
};