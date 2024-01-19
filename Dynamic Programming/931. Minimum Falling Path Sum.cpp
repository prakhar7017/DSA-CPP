// using memoization and dp
class Solution {
public:
    int v[101][101];
     int solve(vector<vector<int>>& matrix, int row,int col,int n){
        //base
        if(row==n-1){
            return matrix[row][col];
        }

        if(v[row][col]!=-1) return v[row][col];

        int minSum=INT_MAX;
        int sum=matrix[row][col];
        if(row+1<n && col-1>=0)
            minSum=min(minSum,sum+solve(matrix,row+1,col-1,n));
        if(row+1<n && col>=0)
            minSum=min(minSum,sum+solve(matrix,row+1,col,n));
        if(row+1<n && col+1<n)
            minSum=min(minSum,sum+solve(matrix,row+1,col+1,n));

        return v[row][col]=minSum;
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int row=0;
        int minSum=INT_MAX;
        memset(v,-1,sizeof(v));
        for(int col=0;col<n;col++){
            minSum=min(minSum,solve(matrix,row,col,n));
        }
        return minSum;
    }
};

// using bottom up dp   
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<vector<int>>v(n,vector<int>(n));

        for(int col=0;col<n;col++){
            v[0][col]=matrix[0][col];
        }

        for(int row=1;row<n;row++){
            for(int col=0;col<n;col++){
                int a= col-1>=0 ? v[row-1][col-1]:INT_MAX;
                int b= col+1 < n ? v[row-1][col+1]:INT_MAX;
                v[row][col]=matrix[row][col]+min({v[row-1][col],a,b});
            }
        }
        int result=INT_MAX;
        for(int col=0;col<n;col++){
            result=min(result,v[n-1][col]);
        }
        return result;
    }
};