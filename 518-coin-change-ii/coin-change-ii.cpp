const int MOD = 1e9 + 7;
class Solution {
public:
    int solve(int index, int amount, vector<int>& coins) {
        // basecase
        if (index == 0) {
            if (amount % coins[index] == 0)
                return 1;
            return 0;
        }
        int exclude = solve(index - 1, amount, coins);
        int include = 0;
        if (coins[index] <= amount)
            include = solve(index, amount - coins[index], coins);

        return (include + exclude);
    }
    int solveUsingTab(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<unsigned long long>> dp(
            n, vector<unsigned long long>(amount + 1, 0));
        for (int amt = 0; amt <= amount; amt++) {
            if (amt % coins[0] == 0)
                dp[0][amt] = 1;
        }

        for (int i = 1; i < n; i++) {
            for (int amt = 0; amt <= amount; amt++) {
                unsigned long long exclude = dp[i - 1][amt];
                unsigned long long include = 0;
                if (coins[i] <= amt)
                    include = dp[i][amt - coins[i]];
                dp[i][amt] = (include + exclude);
            }
        }
        return dp[n - 1][amount];
    }
    int solveUsingSpace(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<unsigned long long>prev(amount+1,0);
        for (int amt = 0; amt <= amount; amt++) {
            if (amt % coins[0] == 0)
                prev[amt] = 1;
        }

        for (int i = 1; i < n; i++) {
            vector<unsigned long long>curr(amount+1,0);
            for (int amt = 0; amt <= amount; amt++) {
                unsigned long long exclude = prev[amt];
                unsigned long long include = 0;
                if (coins[i] <= amt)
                    include = curr[amt - coins[i]];
                curr[amt] = (include + exclude);
            }
            prev=curr;
        }
        return prev[amount];
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        // return solve(n - 1, amount, coins);
        // return solveUsingTab(amount, coins);
        return solveUsingSpace(amount,coins);
    }
};