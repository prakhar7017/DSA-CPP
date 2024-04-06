/*
Count ways to N'th Stair

There are n stairs, and a person standing at the bottom wants to reach the top. The person can climb either 1 stair or 2 stairs at a time. Count the number of ways, the person can reach the top (order does not matter).

*/
class Solution {
  public:
    long long countWays(int n) {
        return (n/2 + 1LL);
    }
};

// time comeplexity: O(1)
// space complexity: O(1)