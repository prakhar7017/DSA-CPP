class Solution {
    private:
    bool isPalindrome(string &s,int st,int e){
        while(st<e){
            if(s[st]!=s[e]){
                return false;
            }
            st++;
            e--;
        }
        return true;
    }
public:
    string longestPalindrome(string s) {
        string ans="";
        for(int i=0;i<s.length();i++){
            for(int j=i;j<s.length();j++){
                if(isPalindrome(s,i,j)){
                    string temp=s.substr(i,j-i+1);
                    ans=temp.length()>ans.length() ? temp : ans;
                }
            }
        }
        return ans;

    }
};

// time complexity: O(n^3)


// Recursive approach
//class Solution {
public:
    int maxLen=1;
    int start=0;
    bool solve(string& s,int i,int j,vector<vector<int>>&dp){
        // base case
        if(i>=j){
            return true;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        bool flag=false;
        if(s[i]==s[j]){
            flag=solve(s,i+1,j-1,dp);
        }
        if(flag){
            int currLen=j-i+1;
            if(currLen>maxLen){
                maxLen=currLen;
                start=i;
            }
        }
        return dp[i][j]=flag;
    }