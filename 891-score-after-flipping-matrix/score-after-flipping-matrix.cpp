class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int rows=grid.size();
        int cols=grid[0].size();

        int sum=0;
        sum+=rows*pow(2,cols-1);

        for(int col=1;col<cols;col++){
            // countSame bits compare with msb
            int countSameBit=0;
            for(int row=0;row<rows;row++){
                if(grid[row][col]==grid[row][0]){
                    ++countSameBit;
                }
            }
            int countOnes=countSameBit;
            int countZeros=rows-countOnes;

            int ones=max(countZeros,countOnes);

            sum+=pow(2,cols-col-1)*ones;
        }
        return sum;
    }
};