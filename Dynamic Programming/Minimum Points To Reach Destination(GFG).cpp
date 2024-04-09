/*
 Minimum Points To Reach Destination
 Given a m*n grid with each cell consisting of positive, negative, or zero point. We can move across a cell only if we have positive points. Whenever we pass through a cell, points in that cell are added to our overall points, the task is to find minimum initial points to reach cell (m-1, n-1) from (0, 0) by following these certain set of rules :
1. From a cell (i, j) we can move to (i + 1, j) or (i, j + 1).
2. We cannot move from (i, j) if your overall points at (i, j) are <= 0.
3. We have to reach at (n-1, m-1) with minimum positive points i.e., > 0.
*/

class Solution{

	public:
	int dfs(int i,int j,int n,int m,vector<vector<int>> &points,vector<vector<int>>&dp){
	    if(i==n-1 && j==m-1){
	        return points[i][j] > 0 ? 1 : abs(points[i][j])+1;
	    }
	    if(dp[i][j]!=-1){
	        return dp[i][j];
	    }
	    int ans=INT_MAX;
	    if(j+1<m){
	        int x= -points[i][j] + dfs(i,j+1,n,m,points,dp);
	        ans=min(ans,x);
	    }
	    if(i+1<n){
	        int y= -points[i][j] + dfs(i+1,j,n,m,points,dp);
	        ans=min(ans,y);
	    }
	    return dp[i][j]=ans<=0 ? 1 : ans;
	}
	int minPoints(int n, int m, vector<vector<int>> points) 
	{ 
	    vector<vector<int>>dp(n,vector<int>(m,-1));
	    return dfs(0,0,n,m,points,dp);
	    
	} 
};


// time complexity : O(n*m)
// space complexity : O(n*m)

// link : https://www.geeksforgeeks.org/problems/minimum-points-to-reach-destination0540/1