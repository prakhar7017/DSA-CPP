class Solution {
public:
    int solveUsingBruteForce(vector<int>& nums) {
        int n = nums.size();
        int maxi = INT_MIN;
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += nums[j];
                maxi = max(maxi, sum);
            }
        }
        return maxi;
    }
    int solveUsingOptimal(vector<int>& nums) {
        int n = nums.size();
        int maxi = INT_MIN;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += nums[i];
            maxi = max(maxi, ans);
            if (ans < 0)
                ans = 0;
        }
        return maxi;
    }
    int maxSubArray(vector<int>& nums) { return solveUsingOptimal(nums); }
};