class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>ans;
        int row=matrix.size();
        int col=matrix[0].size();
        int startRow=0;
        int endRow=row-1;
        int startCol=0;
        int endCol=col-1;
        int total=row*col;
        int count=0;

        while(count<total){
            for(int i=startCol;i<=endCol && count <total;i++){
                ans.push_back(matrix[startRow][i]);
                count++;
            }
            startRow++;
            for(int i=startRow;i<=endRow && count < total;i++){
                ans.push_back(matrix[i][endCol]);
                count++;
            }
            endCol--;
            for(int i=endCol;i>=startCol && count<total;i--){
                ans.push_back(matrix[endRow][i]);
                count++;
            }
            endRow--;
            for(int i=endRow;i>=startRow && count<total;i--){
                ans.push_back(matrix[i][startCol]);
                count++;
            }
            startCol++;
        }
        return ans;
    }
};

// time complexity : O(n*m) n is the number of rows and m is the number of columns