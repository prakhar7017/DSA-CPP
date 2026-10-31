class Solution {
public:
    int m;
    int n;
    int solveUsingMemo(int row,int col,vector<vector<int>>& matrix,vector<vector<int>>&dp){
        if(row == m-1) return matrix[row][col];
        if(dp[row][col]!=-1) return dp[row][col];
        int mini = INT_MAX;
        int sum = matrix[row][col];
        // if(row+1<m && col-1>=0) mini = min(mini,sum + solveUsingMemo(row+1,col-1,matrix,dp));
        // if(row+1<m) mini = min(mini,sum + solveUsingMemo(row+1,col,matrix,dp));
        // if (row+1<m && col+1<n) mini = min(mini,sum + solveUsingMemo(row+1,col+1,matrix,dp));

        for(int shift = -1;shift<=1;shift++){
            if(row+1<m && col+shift>=0 && col+shift<n)
                mini = min(mini,sum + solveUsingMemo(row+1,col+shift,matrix,dp));
        }
        return dp[row][col]= mini;
    }
    int solveUsingBottomUp(vector<vector<int>>& matrix){
        vector<vector<int>>t(m,vector<int>(n));

        for(int col=0;col<n;col++){
            t[0][col]=matrix[0][col];
        }

        for(int row = 1;row<m;row++){
            for(int col=0;col<n;col++){
                int a = INT_MAX;
                int b = INT_MAX;
                if(row-1>=0 && col-1>=0) a = t[row-1][col-1];
                if(row-1>=0 && col+1<n)  b = t[row-1][col+1];
                t[row][col] = matrix[row][col]+ min({t[row-1][col],a,b});
            }
        }

        int ans = INT_MAX;
        for(int col=0;col<n;col++){
            ans = min(ans,t[m-1][col]);
        }
        return ans;
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        // int result = INT_MAX;
        // int row=0;
        // vector<vector<int>>dp(m,vector<int>(n,-1));
        // for(int col=0;col<n;col++){
        //     result = min(result,solveUsingMemo(row,col,matrix,dp));
        // }
        // return result;
        return solveUsingBottomUp(matrix);
    }
};