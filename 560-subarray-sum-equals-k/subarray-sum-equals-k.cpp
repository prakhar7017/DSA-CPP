class Solution {
public:
    int solveUsingBruteForce(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        for (int s = 0; s < n; s++) {
            int sum = 0;
            for (int e = s; e < n; e++) {
                sum += nums[e];
                if (sum == k)
                    ans++;
            }
        }
        return ans;
    }
    int solveUsingOptimal(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        int ans = 0;
        int cumSum = 0;
        mp[cumSum]++;
        for (int i = 0; i < n; i++) { // n
            cumSum += nums[i];
            if (mp.find(cumSum - k) != mp.end()) {
                ans += mp[cumSum - k];
            }
            mp[cumSum]++;
        }
        return ans;
    }
    int subarraySum(vector<int>& nums, int k) {
        return solveUsingOptimal(nums, k);
    }
};