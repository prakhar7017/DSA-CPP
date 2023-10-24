class Solution {
private:
    void twoSum(vector<int>& nums, int target, long long s, long long k, int i, int j) {
        long long newTarget = target - s - k;
        while (i < j) {
            if (i < j && nums[i] + nums[j] < newTarget) {
                i++;
            } else if (i < j && nums[i] + nums[j] > newTarget) {
                j--;
            } else {
                while (i < j && nums[i] == nums[i + 1]) {
                    i++;
                }
                while (i < j && nums[j] == nums[j - 1]) {
                    j--;
                }
                result.push_back({static_cast<int>(s), static_cast<int>(k), nums[i], nums[j]});
                i++;
                j--;
            }
        }
    }

public:
    vector<vector<int>> result;

    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        if (n < 4) {
            return {};
        }
        result.clear();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            for (int j = i + 1; j < n - 2; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }
                twoSum(nums, target, static_cast<long long>(nums[i]), static_cast<long long>(nums[j]), j + 1, n - 1);
            }
        }
        return result;
    }
};

// time complexity : O(n^2) n is the size of the array 