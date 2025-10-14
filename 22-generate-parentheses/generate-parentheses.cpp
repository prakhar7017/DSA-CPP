class Solution {
public:
    bool isValid(string& s){
        int count = 0;
        for(char& ch:s){
            if(ch=='(') count++;
            else if(ch==')') count--;
            if (count<0) return false;
        }
        return count == 0;
    }
    void solveUsingRecursion(string& currString,vector<string>& result, int& n){
        if(currString.length()==2*n){
            if(isValid(currString)) result.push_back(currString);
            return;
        }
        currString.push_back('(');
        solveUsingRecursion(currString,result,n);
        currString.pop_back();
        currString.push_back(')');
        solveUsingRecursion(currString,result,n);
        currString.pop_back();
    }
    vector<string> generateParenthesis(int n) {
        vector<string>result;
        string currString="";
        solveUsingRecursion(currString,result,n);
        return result;
    }
};