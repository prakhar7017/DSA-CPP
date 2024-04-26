/*
    Exit Point in a Matrix

    Given a matrix of size n x m with 0’s and 1’s, you enter the matrix at cell (0,0) in left to right direction. Whenever you encounter a 0 you retain it in the same direction, else if you encounter a 1 you have to change the direction to the right of the current direction and change that 1 value to 0, you have to find out from which index you will leave the matrix at the end.

*/

class Solution {
  public:
    vector<int> FindExitPoint(int n, int m, vector<vector<int>>& matrix) {
        int dir=1;
        int i=0,j=0;
        while(i>=0 && j>=0 && i<n && j<m ){
            if(matrix[i][j]==1){
                matrix[i][j]=0;
                dir=(dir%4)+1; // changing direction  to the right of the current direction.   (current dir) % 4 + 1
            }
            
            if(dir==1){ // right
                ++j;
            }else if(dir==2){ // down
                ++i;
            }else if(dir==3){ // left
                --j;
            }else if(dir==4){ // up
                --i;
            }
        }
        
        if(dir==1) --j; // if we are going out of the matrix from right side
        else if(dir==2) --i; // if we are going out of the matrix from down side
        else if(dir==3) ++j; // if we are going out of the matrix from left side
        else if(dir==4) ++i; // if we are going out of the matrix from up side
        
        return {i,j};
    }
};


// time complexity : O(n*m)
// space complexity : O(1)