class Solution {
public:
    int arr[501][501];
    int solveUsingRec(string &a,string &b,int i,int j){
        // base case
        if(i==a.length()){
            return b.length()-j; 
        }
        if(j==b.length()){
            return a.length()-i;
        }
        if(arr[i][j]!=-1){
            return arr[i][j];
        }
        int ans=0;
        if(a[i]==b[j]){
            ans=0+solveUsingRec(a,b,i+1,j+1);
        }else{
            int insertchar=1+solveUsingRec(a,b,i,j+1);
            int replaceChar=1+solveUsingRec(a,b,i+1,j+1);
            int deleteChar=1+solveUsingRec(a,b,i+1,j);
            ans=min(insertchar,min(replaceChar,deleteChar));
        }
        return arr[i][j]=ans;
    }
    int solveUsingTabu(string &a,string &b){
        vector<vector<int> > dp(a.length()+1,vector<int>(b.length()+1,-1));

        for(int col=0;col<=b.length();col++){
            dp[a.length()][col]=b.length()-col;
        }
        for(int row=0;row<=a.length();row++){
            dp[row][b.length()]=a.length()-row;
        }

        for(int i=a.length()-1;i>=0;i--){
            for(int j=b.length()-1;j>=0;j--){
                int ans=0;
                if(a[i]==b[j]){
                    ans=0+dp[i+1][j+1];
                }else{
                    int insertchar=1+dp[i][j+1];
                    int replaceChar=1+dp[i+1][j+1];
                    int deleteChar=1+dp[i+1][j];
                    ans=min(insertchar,min(replaceChar,deleteChar));
                }
                dp[i][j]=ans;
            }
        }
        return dp[0][0];
    }
    int solveUsingTabuSO(string &a,string &b){
        vector<int>curr(a.length()+1,0);
        vector<int>next(a.length()+1,0);
        // for(int col=0;col<=b.length();col++){
        //     dp[a.length()][col]=b.length()-col;
        // }

        for(int row=0;row<=a.length();row++){
            next[row]=a.length()-row;
        }

        for(int j=b.length()-1;j>=0;j--){
            curr[a.length()]=b.length()-j;
            for(int i=a.length()-1;i>=0;i--){
                int ans=0;
                if(a[i]==b[j]){
                    ans=0+next[i+1];
                }else{
                    int insertchar=1+next[i];
                    int replaceChar=1+next[i+1];
                    int deleteChar=1+curr[i+1];
                    ans=min(insertchar,min(replaceChar,deleteChar));
                }
                curr[i]=ans;
            }
            //shifting
            next=curr;
        }
        return next[0];
    }
    int minDistance(string word1, string word2) {
        // memset(arr,-1,sizeof(arr));
        return solveUsingTabuSO(word1,word2);
    }
};