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

    int solveUsingTab(string &ring,string &key){
        int ringLen=ring.length();
        int keyLen=key.length();

        vector<vector<int>>dp(ringLen+1,vector<int>(keyLen+1,INT_MAX));

        for(int ringIdx=0;ringIdx<ringLen;ringIdx++){
            dp[ringIdx][keyLen]=0;
        }

        for(int keyIdx=keyLen-1;keyIdx>=0;keyIdx--){
            for(int ringIdx=0;ringIdx<ringLen;ringIdx++){
                int result=INT_MAX;
                for(int i=0;i<ringLen;i++){
                    if(ring[i]==key[keyIdx]){
                            int totalSteps=CountSteps(ringIdx,i,ringLen) + 1 + dp[i][keyIdx+1];
                            result=min(result,totalSteps);
                    }
                }
                dp[ringIdx][keyIdx]=result;
            }
        }
        return dp[0][0];
    }





    int findRotateSteps(string ring, string key) {
        vector<vector<int>>dp(ring.length(),vector<int>(key.length(),-1));
        return solveUsingTab(ring,key);
    }
};