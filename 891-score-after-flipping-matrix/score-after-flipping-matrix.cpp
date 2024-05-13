class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int rows=grid.size();
        int cols=grid[0].size();

        for(int row=0;row<rows;row++){
            if(grid[row][0]==0){
                for(int col=0;col<cols;col++){
                    grid[row][col]=1-grid[row][col];
                }
            }
        }

        for(int col=1;col<cols;col++){
            int countZeros=0;
            for(int row=0;row<rows;row++){
                if(grid[row][col]==0){
                    ++countZeros;
                }
            }

            int countOnes=rows-countZeros;

            if(countZeros>countOnes){
                for(int row=0;row<rows;row++){
                    grid[row][col]=1-grid[row][col];
                }
            }
        }

        int sum=0;
        for(int row=0;row<rows;row++){
            for(int col=0;col<cols;col++){
                sum+=grid[row][col]*pow(2,cols-col-1);
            }
        }

        return sum;

    }
};