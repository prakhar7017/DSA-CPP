/*
Optimal Strategy For A Game

You are given an array arr of size n. The elements of the array represent n coin of values v1, v2, ....vn. You play against an opponent in an alternating way. In each turn, a player selects either the first or last coin from the row, removes it from the row permanently, and receives the value of the coin.
You need to determine the maximum possible amount of money you can win if you go first.
Note: Both the players are playing optimally.

*/

class Solution
{
public:
    long long solve(int start, int end, int arr[], vector<vector<long long>> &dp)
    {
        // base case
        if (start > end)
            return 0;
        if (start == end)
            return arr[start];
        if (dp[start][end] != -1)
            return dp[start][end];
        long long startInclude = arr[start] + min(solve(start + 2, end, arr, dp), solve(start + 1, end - 1, arr, dp));
        long long endInclude = arr[end] + min(solve(start + 1, end - 1, arr, dp), solve(start, end - 2, arr, dp));
        return dp[start][end] = max(startInclude, endInclude);
    }
    long long maximumAmount(int n, int arr[])
    {
        int start = 0;
        int end = n - 1;
        vector<vector<long long>> dp(n, vector<long long>(n, -1));
        return solve(start, end, arr, dp);
    }
};

// time complexity: O(n)
// space complexity: O(n)

// link : https://www.geeksforgeeks.org/problems/optimal-strategy-for-a-game-1587115620/1