class Solution {
    public void swap(int[][] mat,int row,int col){
        int temp=mat[row][col];
        mat[row][col]=mat[col][row];
        mat[col][row]=temp;
    }
    public void reverse(int[] row){
        int i=0;
        int j=row.length-1;
        while(i<=j){
            int temp=row[i];
            row[i]=row[j];
            row[j]=temp;
            i++;j--;
        }
    }
    public void rotate(int[][] matrix) {
        // transpose
        for(int row=0;row<matrix.length;row++){
            for(int col=row;col<matrix[row].length;col++){
                swap(matrix,row,col);
            }
        }

        //reverse each row
        for(int i=0;i<matrix.length;i++){
            reverse(matrix[i]);
        }
    }
}