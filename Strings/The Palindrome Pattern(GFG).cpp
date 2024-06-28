/*
    The Palindrome Pattern

    Given a two-dimensional integer array arr of dimensions n x n, consisting solely of zeros and ones, identify the row or column (using 0-based indexing) where all elements form a palindrome. If multiple palindromes are identified, prioritize the palindromes found in rows over those in columns. Within rows or columns, the palindrome with the smaller index takes precedence. The result should be represented by the index followed by either 'R' or 'C', indicating whether the palindrome was located in a row or column. The output should be space-separated. If no palindrome is found, return the string -1.

*/

class Solution {
  public:
    bool isPalindromeRow(int row,vector<vector<int>> &arr){
        int cols=arr[0].size();
        for(int col=0;col<cols;col++){
            if(arr[row][col]!=arr[row][cols-col-1]){
                return false;
            }
        }
        return true;
    }
    bool isPalindromeColumn(int col,vector<vector<int>> &arr){
        int rows=arr.size();
        for(int row=0;row<rows;row++){
            if(arr[row][col]!=arr[rows-row-1][col]){
                return false;
            }
        }
        return true;
    }
    
    

    string pattern(vector<vector<int>> &arr) {
        int rows=arr.size();
        int cols=arr[0].size();
        
        for(int row=0;row<rows;row++){
            if(isPalindromeRow(row,arr)){
                return to_string(row)+" "+"R";
            }
        }
        
        for(int col=0;col<cols;col++){
            for(int row=0;row<rows;row++){
                if(isPalindromeColumn(col,arr)){
                    return to_string(col)+" "+'C';
                }
            }
        }
        return to_string(-1);
    }
};

// time complexity: o(n^2)
// space complexity: o(n)