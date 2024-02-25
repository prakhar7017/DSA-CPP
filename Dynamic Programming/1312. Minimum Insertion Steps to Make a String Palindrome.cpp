class Solution {
public:
    int subseq_Helper(string &s1,string &s2,int i,int j){
        // basecase
        if(i>=s1.length() || j>=s2.length()){
            return 0;
        }

        int ans=0;
        if(s1[i]==s2[j]){
            ans=1+subseq_Helper(s1,s2,i+1,j+1);
        }else{
            ans=0+max(subseq_Helper(s1,s2,i,j+1),subseq_Helper(s1,s2,i+1,j));
        }
        return ans;
    }
    int subseqTab_Helper(string &s1,string &s2){
        vector<vector<int>>dp(s1.size()+1,vector<int>(s2.size()+1,0));
        for(int i=s1.size()-1;i>=0;i--){
            for(int j=s2.size()-1;j>=0;j--){
                int ans=0;
                if(s1[i]==s2[j]){
                    ans=1+dp[i+1][j+1];
                }else{
                    ans=0+max(dp[i][j+1],dp[i+1][j]);
                }
                dp[i][j]=ans;
            }
        }
        return dp[0][0];
    }
    int subseqSO_Helper(string &s1,string &s2){
        vector<int>currRow(s2.size()+1,0);
        vector<int>nextRow(s2.size()+1,0);

        for(int i=s1.size()-1;i>=0;i--){
            for(int j=s2.size()-1;j>=0;j--){
                int ans=0;
                if(s1[i]==s2[j]){
                    ans=1+nextRow[j+1];
                }else{
                    ans=0+max(currRow[j+1],nextRow[j]);
                }
                currRow[j]=ans;
            }
            // shifting
            nextRow=currRow;
        }
        return nextRow[0];
    }
    int minInsertions(string s) {
        string temp=s;
        reverse(s.begin(),s.end());
        int palinSubSeq_len=subseqSO_Helper(temp,s);
        int inpStr_len=s.size();
        return inpStr_len-palinSubSeq_len;
    }
};