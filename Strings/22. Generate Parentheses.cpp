class Solution {
    void generateParenthesisHelper(int open,int close,int& n,
    vector<string>&ans,string output){
        //base case
        if(output.size()==n*2){
            ans.push_back(output);
            return;
        }

        if(open<n){
            output+="(";
            //recursive call
            generateParenthesisHelper(open+1,close,n,ans,output);
            //backtrack
            output.pop_back();
        }
        if(close<open){
            output+=")";
            // recursive call 
            generateParenthesisHelper(open,close+1,n,ans,output);
            // backtrack
            output.pop_back();
        };
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string output="";
        generateParenthesisHelper(0,0,n,ans,output);
        return ans;
    }
};