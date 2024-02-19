class Solution
{
private:
    int mincostTickets_Helper(vector<int> &days, vector<int> &costs, int i, vector<int> &dp)
    {
        // base case
        if (i >= days.size())
        {
            return 0;
        }
        if (dp[i] != -1)
        {
            return dp[i];
        }
        // 1 day pass
        int cost1 = costs[0] + mincostTickets_Helper(days, costs, i + 1, dp);

        // 7 day pass
        int passEndingDay = days[i] + 7 - 1;
        int currentDay = i;
        while (currentDay < days.size() && days[currentDay] <= passEndingDay)
        {
            currentDay++;
        }
        int cost7 = costs[1] + mincostTickets_Helper(days, costs, currentDay, dp);

        // 30 day pass
        passEndingDay = days[i] + 30 - 1;
        currentDay = i;
        while (currentDay < days.size() && days[currentDay] <= passEndingDay)
        {
            currentDay++;
        }
        int cost30 = costs[2] + mincostTickets_Helper(days, costs, currentDay, dp);

        return dp[i] = min(cost1, min(cost7, cost30));
    }
    int solveUsingTab(vector<int> &days, vector<int> &costs)
    {
        vector<int> dp(days.size() + 1, 0);
        dp[days.size()] = 0;
        for (int i = days.size() - 1; i >= 0; i--)
        {
            // 1 day pass
            int cost1 = costs[0] + dp[i + 1]; // mincostTickets_Helper(days,costs,i+1);

            // 7 day pass
            int passEndingDay = days[i] + 7 - 1;
            int currentDay = i;
            while (currentDay < days.size() && days[currentDay] <= passEndingDay)
            {
                currentDay++;
            }
            int cost7 = costs[1] + dp[currentDay]; // mincostTickets_Helper(days,costs,currentDay,dp);

            // 30 day pass
            passEndingDay = days[i] + 30 - 1;
            currentDay = i;
            while (currentDay < days.size() && days[currentDay] <= passEndingDay)
            {
                currentDay++;
            }
            int cost30 = costs[2] + dp[currentDay]; // mincostTickets_Helper(days,costs,currentDay,dp);

            dp[i] = min(cost1, min(cost7, cost30));
        }
        return dp[0];
    }

public:
    int mincostTickets(vector<int> &days, vector<int> &costs)
    {
        // vector<int>dp(days.size()+1,-1);
        return solveUsingTab(days, costs);
    }
};