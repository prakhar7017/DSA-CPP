class Solution {
public:
    void solve(int &n,string &curr,vector<string>&ans){
        // base case
        if(curr.length()==n) {
            ans.push_back(curr);
            return;
        }

        for(char ch='a' ;ch<='c';ch++){
            // base condition
            if(!curr.empty() && curr.back()==ch) continue;

            //do
            curr.push_back(ch);
            //explore
            solve(n,curr,ans);
            // undo
            curr.pop_back();

        }
    }
    string getHappyString(int n, int k) {
        string curr="";
        vector<string>ans;
        solve(n,curr,ans);
        if(k>ans.size()) return "";
        return ans[k-1];
    }
};