class Solution {
public:
    int arr[1001][1001];
    int solve(string&s1,string&s2,int i,int j){
        if(i>=s1.length() || j>=s2.length()){
            return 0;
        }
        if(arr[i][j]!=-1){
            return arr[i][j];
        }
        if(s1[i]==s2[j]){
            return arr[i][j]=1+solve(s1,s2,i+1,j+1);
        }
        int include_i=solve(s1,s2,i+1,j);
        int include_j=solve(s1,s2,i,j+1);
        return arr[i][j]=max(include_i,include_j);
    }
    int longestCommonSubsequence(string text1, string text2) {
        memset(arr,-1,sizeof(arr));
        int ans=solve(text1,text2,0,0);
        return ans;
    }
};

// time complexity: O(n+1*m+1)

// bottom-up approach
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

