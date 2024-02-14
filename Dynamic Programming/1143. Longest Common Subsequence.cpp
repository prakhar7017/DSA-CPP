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
//************************************ dp approaches
class Solution {
public:
    int arr[1001][1001];
    int solveUsingRec(string &a,string &b,int i,int j){
        // base case
        if(i>=a.length()){
            return 0;
        }
        if(j>=b.length()){
            return 0;
        }
        //processing
        if(arr[i][j]!=-1){
            return arr[i][j];
        }
        int ans=0;
        if(a[i]==b[j]){
            ans=1+solveUsingRec(a,b,i+1,j+1);
        }else{
            ans=0+max(solveUsingRec(a,b,i+1,j),solveUsingRec(a,b,i,j+1));
        }
        return arr[i][j]=ans;
    }
    int solveUsingTabulation(string &a,string &b){
        vector<vector<int> > dp(a.length()+1,vector<int>(b.length()+1,0));
        for(int i=a.length()-1;i>=0;i--){
            for(int j=b.length()-1;j>=0;j--){
                int ans=0;
                if(a[i]==b[j]){
                    ans=1+dp[i+1][j+1];
                }else{
                    ans=0+max(dp[i+1][j],dp[i][j+1]);
                }
                dp[i][j]=ans;
            }
        }
        return dp[0][0];
    }
    int solveUsingTabulationSO(string &a,string &b){
        vector<int>curr(a.length()+1,0);
        vector<int>next(a.length()+1,0);
        for(int j=b.length()-1;j>=0;j--){
            for(int i=a.length()-1;i>=0;i--){
                int ans=0;
                if(a[i]==b[j]){
                    ans=1+next[i+1];
                }else{
                    ans=0+max(next[i],curr[i+1]);
                }
                curr[i]=ans;
            }
            // shifiting 
            next=curr;
        }
        return next[0];
    }
    int longestCommonSubsequence(string text1, string text2) {
        // int i=0;
        // int j=0;
        // memset(arr,-1,sizeof(arr));
        return solveUsingTabulationSO(text1,text2);
    }
};



