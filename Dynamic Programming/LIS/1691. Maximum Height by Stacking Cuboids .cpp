class Compare
{
public:
    bool operator()(const vector<int> &a, const vector<int> &b)
    {
        return a[0] < b[0] || (a[0] == b[0] && a[1] < b[1]) || (a[0] == b[0] && a[1] == b[1] && a[2] < b[2]);
    }
};
class Solution
{
public:
    int t[101][101];
    bool check(vector<int> &a, vector<int> &b)
    {
        if (b[0] <= a[0] && b[1] <= a[1] && b[2] <= a[2])
        {
            return true;
        }
        // if(a[0]<=b[0] && a[1]<=b[1] && a[2]<=b[2]){
        //     return true;
        // }
        return false;
    }
    int solveUsingRec(vector<vector<int>> &cuboids, int prev, int curr)
    {
        if (curr >= cuboids.size())
        {
            return 0;
        }
        if (t[curr][prev + 1] != -1)
        {
            return t[curr][prev + 1];
        }
        int include = 0;
        if (prev == -1 || check(cuboids[curr], cuboids[prev]))
        {
            include = cuboids[curr][2] + solveUsingRec(cuboids, curr, curr + 1);
        }
        int exclude = 0 + solveUsingRec(cuboids, prev, curr + 1);

        return t[curr][prev + 1] = max(include, exclude);
    }
    int solveUsingTab(vector<vector<int>> &cuboids)
    {
        int n = cuboids.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int curr = n - 1; curr >= 0; curr--)
        {
            for (int prev = curr - 1; prev >= -1; prev--)
            {
                int include = 0;
                if (prev == -1 || check(cuboids[curr], cuboids[prev]))
                {
                    include = cuboids[curr][2] + dp[curr + 1][curr + 1];
                }
                int exclude = 0 + dp[prev + 1][curr + 1];
                dp[prev + 1][curr] = max(include, exclude);
            }
        }
        return dp[0][0];
    }
    int solveUsingTabSO(vector<vector<int>> &cuboids)
    {
        int n = cuboids.size();
        vector<int> currRow(n + 1, 0);
        vector<int> nextRow(n + 1, 0);

        for (int curr = n - 1; curr >= 0; curr--)
        {
            for (int prev = curr - 1; prev >= -1; prev--)
            {
                int include = 0;
                if (prev == -1 || check(cuboids[curr], cuboids[prev]))
                {
                    include = cuboids[curr][2] + nextRow[curr + 1];
                }
                int exclude = 0 + nextRow[prev + 1];
                currRow[prev + 1] = max(include, exclude);
            }
            // shifitng
            nextRow = currRow;
        }
        return currRow[0];
    }

    // not working for all test cases to be resolved later
    int solveUsingBs(vector<vector<int>> &cuboids)
    {
        int n = cuboids.size();
        vector<vector<int>> ans;
        ans.push_back(cuboids[0]);

        for (int i = 1; i < n; i++)
        {
            if (cuboids[i][0] >= ans.back()[0] && cuboids[i][1] >= ans.back()[1] && cuboids[i][2] >= ans.back()[2])
            {
                ans.push_back(cuboids[i]);
            }
            else
            {
                int index = lower_bound(ans.begin(), ans.end(), cuboids[i], Compare()) - ans.begin();
                ans[index] = cuboids[i];
            }
        }

        int maxHeight = 0;
        for (const auto &cuboid : ans)
        {
            maxHeight += cuboid[2];
        }

        return maxHeight;
    }
    int maxHeight(vector<vector<int>> &cuboids)
    {
        memset(t, -1, sizeof(t));
        for (auto &a : cuboids)
        {
            sort(a.begin(), a.end());
        }

        sort(cuboids.begin(), cuboids.end());
        // int prev=-1;
        // int curr=0;
        return solveUsingBs(cuboids);
    }
};