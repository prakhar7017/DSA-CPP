class Solution {
public:
    int solveUsingRec(string& s1,string &s2,int i,int j,vector<vector<int>>&dp){
        int cost=0;
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        // base case
        if(i==s1.size() || j==s2.size()){
            // ruturns the sum of ASCII
            for(int x=j;x<s2.size();x++){
                cost+=s2[x];
            }
            for(int x=i;x<s1.size();x++){
                cost+=s1[x];
            }
        }else if (s1[i]==s2[j]){
            cost=solveUsingRec(s1,s2,i+1,j+1,dp);
        }else{
            int cost1=s1[i]+solveUsingRec(s1,s2,i+1,j,dp);
            int cost2=s2[j]+solveUsingRec(s1,s2,i,j+1,dp);
            cost=min(cost1,cost2);
        }
        return dp[i][j]=cost;
    }
    int solveUsingRecTab(string& s1,string &s2){
        vector<vector<int>>dp(s1.size()+1,vector<int>(s2.size()+1,0));
        for(int row=s1.size()-1;row>=0;row--){
            dp[row][s2.size()]=s1[row]+dp[row+1][s2.size()];
        }
        for(int col=s2.size()-1;col>=0;col--){
            dp[s1.size()][col]=s2[col]+dp[s1.size()][col+1];
        }

        for(int i=s1.size()-1;i>=0;i--){
            for(int j=s2.size()-1;j>=0;j--){
                int cost=0;
                if (s1[i]==s2[j]){
                    cost=dp[i+1][j+1];
                }else{
                    int cost1=s1[i]+dp[i+1][j];//solveUsingRec(s1,s2,i+1,j,dp);
                    int cost2=s2[j]+dp[i][j+1];//solveUsingRec(s1,s2,i,j+1,dp);
                    cost=min(cost1,cost2);
                }
                dp[i][j]=cost;
            }
        }
        return dp[0][0];
    }
    int solveUsingRecSO(string& s1,string &s2){
        vector<int>nextRow(s2.size()+1,0);
        vector<int>currRow(s2.size()+1,0);

        for (int i = 0; i <= s1.size(); i++) {
            nextRow[i] = s1.size() - i;
        }

        for (int j = s2.size() - 1; j >= 0; j--) {
           
            currRow[s1.size()] = s2.size() - j;
        }

        // nextRow[]
        // for(int row=s1.size()-1;row>=0;row--){
        //     dp[row][s2.size()]=s1[row]+dp[row+1][s2.size()];
        // }
        // for(int col=s2.size()-1;col>=0;col--){
        //     dp[s1.size()][col]=s2[col]+dp[s1.size()][col+1];
        // }


        for(int i=s1.size()-1;i>=0;i--){
            for(int j=s2.size()-1;j>=0;j--){
                int cost=0;
                if (s1[i]==s2[j]){
                    cost=nextRow[j+1];
                }else{
                    int cost1=s1[i]+nextRow[j];//solveUsingRec(s1,s2,i+1,j,dp);
                    int cost2=s2[j]+currRow[j+1];//solveUsingRec(s1,s2,i,j+1,dp);
                    cost=min(cost1,cost2);
                }
                currRow[j]=cost;
            }
        }
        return nextRow[0];
    }
    int minimumDeleteSum(string s1, string s2) {
        // vector<vector<int>>dp(s1.size()+1,vector<int>(s2.size()+1,-1));
        return solveUsingRecSO(s1,s2);
    }
};