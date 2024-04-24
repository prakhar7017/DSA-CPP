/*
    Paths to reach origin 

    You are standing on a point (x, y) and you want to go to the origin (0, 0) by taking steps either left or down i.e. from each point you are allowed to move either in (x-1, y) or (x, y-1). Find the number of paths from point to origin.
*/

class Solution
{
public:
    int solve(int x,int y, vector<vector<int>>&dp){
        // base case
        if( x<0 || y<0) return 0;
        
        if(x==0 && y==0) {
            return 1;
        }
        
        if(dp[x][y]!=-1){
            return dp[x][y];
        }
        
        int leftAns=solve(x-1,y,dp);
        int rightAns=solve(x,y-1,dp);
        dp[x][y]=(leftAns+rightAns) % 1000000007;
    }
    int BottomUp(int x,int y){
        vector<vector<int>>dp(x+1,vector<int>(y+1,0));
        dp[0][0]=1; // base case means origin
        for(int i=0;i<=x;i++){
            int topAns=0;
            int rightAns=0;
            for(int j=0;j<=y;j++){
                if(i==0 || y==0 ) {// points lying on x-axis or y-axis have onyl 1 path to reach origin
                    dp[i][j]=1;
                }else{ // for other points
                    rightAns=dp[i-1][j];
                    topAns=dp[i][j-1];
                    dp[i][j]=(rightAns+topAns)%1000000007;
                }
            }
        }
        
        return dp[x][y];
    }
    int ways(int x, int y)
    {
        if(x==0 && y==0 ) return 0;
        vector<vector<int>>dp(x+1,vector<int>(y+1,-1));
        int ans=BottomUp(x,y);
        return ans ;
    }
};

// time complexity: O(x*y)
// space complexity: O(x*y)