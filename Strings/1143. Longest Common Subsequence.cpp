class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m=text1.length();
        int n=text2.length();

        vector<vector<int>>arr(m+1,vector<int>(n+1));

        for(int row=0;row<m+1;row++){
            arr[row][0]=0;
        }
        for(int col=0;col<n+1;col++){
            arr[0][col]=0;
        }
        for(int i=1;i<m+1;i++){
            for(int j=1;j<n+1;j++){
                if(text1[i-1]==text2[j-1]){
                    arr[i][j]=1+arr[i-1][j-1];
                }else{
                    arr[i][j]=max(arr[i-1][j],arr[i][j-1]);
                }
            }
        }
        return arr[m][n];
    }
};