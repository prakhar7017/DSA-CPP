class Solution {
public:
    vector<vector<int>> result;
    void twoSum(int i, int j, int target, vector<int>& nums) {
        while (i < j) {
            int sum = nums[i] + nums[j];
            if (sum == target) {
                result.push_back({-target, nums[i++], nums[j--]});
                while (i < j && nums[i] == nums[i - 1])
                    i++;
                while (i < j && nums[j] == nums[j + 1])
                    j--;
            } else if (sum < target)
                i++;
            else
                j--;
        }
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        if (n < 3)
            return {};
        result.clear();
        sort(begin(nums), end(nums));
        for (int i = 0; i < n - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            twoSum(i + 1, n - 1, -nums[i], nums);
        }
        return result;
    }
};