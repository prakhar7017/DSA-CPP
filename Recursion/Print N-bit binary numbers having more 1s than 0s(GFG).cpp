// Problem Statement: Print N-bit binary numbers having more 1s than 0s.

// description : Given a positive integer n. Your task is to generate a string list of all n-bit binary numbers where, for any prefix of the number, there are more or an equal number of 1's than 0's. The numbers should be sorted in decreasing order of magnitude.

class Solution
{
public:
    void solve(int oneCount, int zeroCount, vector<string> &ans, string output, int &n)
    {
        // base case
        if (oneCount + zeroCount == n)
        {
            ans.push_back(output);
            return;
        }

        solve(oneCount + 1, zeroCount, ans, output + '1', n);
        if (oneCount > zeroCount)
        {
            solve(oneCount, zeroCount + 1, ans, output + '0', n);
        }
    }
    vector<string> NBitBinary(int n)
    {
        vector<string> ans;
        int zeroCount = 0;
        int oneCount = 0;
        solve(oneCount, zeroCount, ans, "", n);
        return ans;
    }
};

// time complexity : O(2^n)
// space complexity : O(2^n)