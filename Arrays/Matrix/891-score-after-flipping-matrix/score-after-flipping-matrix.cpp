
// without modfing the input matrix
class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int rows=grid.size();
        int cols=grid[0].size();

        int sum=0;
        sum+=rows*pow(2,cols-1); // msb is always 1 so add 2^(cols-1) to sum

        for(int col=1;col<cols;col++){ // phle col ko upar handle karliya hh so ab col=1 se start karenge
            // countSame bits compare with msb
            int countSameBit=0; // count of bits that are same as msb
            for(int row=0;row<rows;row++){
                if(grid[row][col]==grid[row][0]){
                    ++countSameBit;
                }
            }
            int countOnes=countSameBit; // count of bits that are 1
            int countZeros=rows-countOnes; // count of bits that are 0

            int ones=max(countZeros,countOnes);// flip the bits that are less in number

            sum+=pow(2,cols-col-1)*ones; // add the contribution of this col to sum
        }
        return sum;
    }
};

// with modfing the input matrix
class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int rows=grid.size();
        int cols=grid[0].size();

        for(int row=0;row<rows;row++){
            if(grid[row][0]==0){ // flip the row if msb is 0
                for(int col=0;col<cols;col++){
                    grid[row][col]=1-grid[row][col];
                }
            }
        }

        for(int col=1;col<cols;col++){ // flip the col if count of 0s is more than count of 1s
            int countZeros=0;
            for(int row=0;row<rows;row++){
                if(grid[row][col]==0){// count of 0s
                    ++countZeros;
                }
            }

            int countOnes=rows-countZeros; // count of 1s

            if(countZeros>countOnes){// flip the col
                for(int row=0;row<rows;row++){
                    grid[row][col]=1-grid[row][col];
                }
            }
        }

        int sum=0;
        for(int row=0;row<rows;row++){
            for(int col=0;col<cols;col++){
                sum+=grid[row][col]*pow(2,cols-col-1); // calculate the sum
            }
        }

        return sum;

    }
};