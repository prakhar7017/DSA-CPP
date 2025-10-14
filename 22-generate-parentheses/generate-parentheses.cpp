class Solution {
public:
    bool isValid(string& s) {
        int count = 0;
        for (char& ch : s) {
            if (ch == '(')
                count++;
            else if (ch == ')')
                count--;
            if (count < 0)
                return false;
        }
        return count == 0;
    }
    void solveUsingRecursion(string& currString, vector<string>& result,
                             int& n) {
        if (currString.length() == 2 * n) {
            if (isValid(currString))
                result.push_back(currString);
            return;
        }
        currString.push_back('(');
        solveUsingRecursion(currString, result, n);
        currString.pop_back();
        currString.push_back(')');
        solveUsingRecursion(currString, result, n);
        currString.pop_back();
    }

    void solveUsingRecursionOptimised(string currString, vector<string>& result,
                                      int n, int open, int close) {
        if (currString.length() == 2 * n) {
            result.push_back(currString);
            return;
        }

        if (open < n) {
            solveUsingRecursionOptimised(currString + "(", result, n, open + 1,
                                         close);
        }

        if (close < open) {
            solveUsingRecursionOptimised(currString + ")", result, n, open,
                                         close + 1);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string currString = "";
        // solveUsingRecursion(currString, result, n, 0, 0);
        solveUsingRecursionOptimised(currString, result, n, 0, 0);
        return result;
    }
}; // (()) ((((