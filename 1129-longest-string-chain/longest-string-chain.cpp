class Solution {
public:
    static bool lamda(string& word1, string& word2) {
        return word1.length() < word2.length();
    }
    bool isPredecessor(string& s1, string& s2) {
        int n = s1.length();
        int m = s2.length();
        if (n > m || m - n != 1)
            return false;
        int i=0,j=0;
        while(i<n && j<m){
            if(s1[i]==s2[j]) i++;
            j++;
        }
        return i==n;
    }
    int solveUsingRec(int idx, int prev, vector<string>& words,vector<vector<int>>& dp) {
        if (idx >= words.size())
            return 0;

        if(dp[idx][prev+1]!=-1) return dp[idx][prev+1];    
        int include = 0;
        int exclude = 0;
        if (prev == -1 || isPredecessor(words[prev], words[idx])) {
            include = 1 + solveUsingRec(idx + 1, idx, words,dp);
        }
        exclude = 0 + solveUsingRec(idx + 1, prev, words,dp);

        return dp[idx][prev+1]=max(include, exclude);
    }
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        sort(begin(words), end(words), lamda);
        int prev = -1;
        return solveUsingRec(0, prev, words,dp);
    }
};