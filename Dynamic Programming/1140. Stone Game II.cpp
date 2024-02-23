class Solution {
public:
    int solve(vector<int>& piles,int index,int m,bool alice,vector<vector<vector<int>>>&dp){
        // base case
        if(index>=piles.size()) return 0;

        if(dp[index][m][alice]!=-1){
            return dp[index][m][alice];
        }

        int ans=alice ? INT_MIN : INT_MAX ;
        int total=0;
        for(int x=1;x<=2*m;x++){
            if(index+x-1 >= piles.size()) break;
            total+=piles[index+x-1];
            if(alice){
                ans=max(ans,total+solve(piles,index+x,max(x,m),!alice,dp));
            }else{
                ans=min(ans,solve(piles,index+x,max(x,m),!alice,dp));
            }
        }
        return dp[index][m][alice]=ans;
    }
    int solveTab(vector<int>& piles){
        vector<vector<vector<int>>>dp(piles.size()+1,vector<vector<int>>(piles.size()+1,vector<int>(2,0)));
        for(int index=piles.size()-1;index>=0;index--){
            for(int M=piles.size();M>=1;M--){
                for(int alice=0;alice<=1;alice++){
                    int ans=alice ? INT_MIN : INT_MAX ;
                    int total=0;
                    for(int x=1;x<=2*M;x++){
                        if(index+x-1 >= piles.size()) break;
                        total+=piles[index+x-1];
                        if(alice){
                            ans=max(ans,total+dp[index+x][max(x,M)][!alice]);
                        }else{
                            ans=min(ans,dp[index+x][max(x,M)][!alice]);
                        }
                    }
                    dp[index][M][alice]=ans;
                }
            }
        }
        return dp[0][1][1];
    }
    int stoneGameII(vector<int>& piles) {
        //vector<vector<vector<int>>>dp(piles.size()+1,vector<vector<int>>(piles.size()+1,vector<int>(2,-1)));
        //return solve(piles,0,1,true,dp);
        return solveTab(piles);
    }
};

