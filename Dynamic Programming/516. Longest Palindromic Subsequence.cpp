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
    int longestPalindromeSubseq(string s) {
        string temp=s;
        reverse(temp.begin(),temp.end());
        return solveUsingTabulationSO(temp,s); 
    }
};