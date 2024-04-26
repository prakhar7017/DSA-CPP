class Solution {
public:
    int rows;
    int cols;
    int solveUsingMemo(int row,int col,vector<vector<int>>& grid,vector<vector<int>>& dp){
        // base case
        if(row==rows-1){ // on last row
            return grid[row][col];
        }
        if(dp[row][col]!=-1){
            return dp[row][col];
        }
        int ans=INT_MAX;
        for(int nextCol=0;nextCol<cols;nextCol++){
            if(nextCol!=col){
                ans=min(ans,solveUsingMemo(row+1,nextCol,grid,dp));
            }
        }

        return dp[row][col]=grid[row][col]+ans; // current[row][col] + neche ki rows ka min ans
    }

    int solveUsingTab(vector<vector<int>>& grid){
        vector<vector<int>>dp(rows+1,vector<int>(cols+1,INT_MAX));

        // setting up initial state, filling last row
        for(int col=0;col<cols;col++){
            dp[rows-1][col]=grid[rows-1][col];
        }

        // moving in reverse dir
        // from n-2 row to 0 row.
        for(int row=rows-2;row>=0;row--){ 
            for(int col=0;col<cols;col++){ // current col
                int ans=INT_MAX;
                for(int nextCol=0;nextCol<cols;nextCol++){ // next col , below of col
                    if(nextCol!=col){
                        ans=min(ans,dp[row+1][nextCol]);
                    }
                }
                dp[row][col]=grid[row][col]+ans; // current[row][col] + neche a min ans;
            }
        }
        int result=INT_MAX;
        for(int col=0;col<cols;col++){
            result=min(result,dp[0][col]);
        }
        return result;
    }

    int solveUsingTabOptimised(vector<vector<int>>& grid){
        vector<vector<int>>dp(rows+1,vector<int>(cols+1,INT_MAX));

        int firstSmallestCol=-1;
        int secondSmallestCol=-1;
        // setting up initial state, filling last row and calculating firstSmallestCol ,secondSmallesCol
        for(int col=0;col<cols;col++){
            dp[rows-1][col]=grid[rows-1][col];

            if(firstSmallestCol==-1 ||  dp[rows-1][col]<=dp[rows-1][firstSmallestCol]){ // updation of firstSmallestCol
                secondSmallestCol=firstSmallestCol;
                firstSmallestCol=col;
            } else if(secondSmallestCol==-1 || dp[rows-1][col]<=dp[rows-1][secondSmallestCol]){ // updation of secondSmallesCol
                secondSmallestCol=col;
            }
        }

        // moving in reverse dir
        // from n-2 row to 0 row.
        for(int row=rows-2;row>=0;row--){ 
            int minCol1=-1;
            int minCol2=-1;
            for(int col=0;col<cols;col++){ // current col
                if(col!=firstSmallestCol){
                    dp[row][col]=grid[row][col]+dp[row+1][firstSmallestCol];
                }else{
                    dp[row][col]=grid[row][col]+dp[row+1][secondSmallestCol];
                }

                if(minCol1==-1 || dp[row][col]<=dp[row][minCol1]){
                    minCol2=minCol1;
                    minCol1=col;
                }else if(minCol2==-1 || dp[row][col]<=dp[row][minCol2]){
                    minCol2=col;
                }
            }
            firstSmallestCol=minCol1;
            secondSmallestCol=minCol2;
        }
        return dp[0][firstSmallestCol];
    }


    int solveUsingSpaceOptmised(vector<vector<int>>& grid){
        int firstSmallestCol=-1;
        int secondSmallestCol=-1;
        int firstSmallestColVal=-1;
        int secondSmallestColVal=-1;
        // setting up initial state, filling last row and calculating firstSmallestCol ,secondSmallesCol
        for(int col=0;col<cols;col++){
            if(firstSmallestCol==-1 ||  grid[rows-1][col]<=firstSmallestColVal){ // updation of firstSmallestCol
                secondSmallestCol=firstSmallestCol;
                secondSmallestColVal=firstSmallestColVal;

                firstSmallestCol=col;
                firstSmallestColVal=grid[rows-1][col];
            } else if(secondSmallestCol==-1 || grid[rows-1][col]<=secondSmallestColVal){ // updation of secondSmallesCol
                secondSmallestCol=col;
                secondSmallestColVal=grid[rows-1][col];
            }
        }

        // moving in reverse dir
        // from n-2 row to 0 row.
        for(int row=rows-2;row>=0;row--){ 
            int minCol1=-1;
            int minCol2=-1;

            int minCol1Val=-1;
            int minCol2Val=-1;
            for(int col=0;col<cols;col++){ // current col
                int ans=INT_MAX;
                if(col!=firstSmallestCol){
                    ans=grid[row][col]+firstSmallestColVal;
                }else{
                    ans=grid[row][col]+secondSmallestColVal;
                }

                if(minCol1==-1 || ans<=minCol1Val){
                    minCol2=minCol1;
                    minCol2Val=minCol1Val;
                    minCol1=col;
                    minCol1Val=ans;
                }else if(minCol2==-1 || ans<=minCol2Val){
                    minCol2=col;
                    minCol2Val=ans;
                }
            }
            firstSmallestCol=minCol1;
            firstSmallestColVal=minCol1Val;
            secondSmallestCol=minCol2;
            secondSmallestColVal=minCol2Val;
        }
        return firstSmallestColVal;
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        rows=grid.size();
        cols=grid[0].size();
        int result=INT_MAX;
        // vector<vector<int>>dp(rows+1,vector<int>(cols+1,-1));
        // for(int col=0;col<cols;col++){
        //     result=min(result,solveUsingMemo(0,col,grid,dp));
        // }
        result=solveUsingSpaceOptmised(grid);
        return result;
    }
};