class Solution {
private:
    long long merge(vector<int>& nums, vector<int>& temp, int s, int e, int mid) {
        int leftIndex = s;
        int rightIndex = mid + 1;
        int mainArrayIndex = s;
        long long c = 0;
        while (leftIndex <= mid && rightIndex <= e) {
            if (nums[leftIndex] <= nums[rightIndex]) {
                temp[mainArrayIndex++] = nums[leftIndex++];
            } else {
                temp[mainArrayIndex++] = nums[rightIndex++];
            }
        }
        while (leftIndex <= mid) {
            temp[mainArrayIndex++] = nums[leftIndex++];
        }
        while (rightIndex <= e) {
            temp[mainArrayIndex++] = nums[rightIndex++];
        }
        leftIndex = s;
        rightIndex = mid + 1;
        while (leftIndex <= mid && rightIndex <= e) {
            if (static_cast<long long>(nums[leftIndex]) > 2LL * nums[rightIndex]) {
                c += mid - leftIndex + 1;
                rightIndex++;
            } else {
                leftIndex++;
            }
        }
        for (int i = s; i <= e; i++) {
            nums[i] = temp[i];
        }
        return c;
    }

    long long reversePairHelper(vector<int>& nums, vector<int>& temp, int s, int e) {
        if (s >= e) {
            return 0;
        }
        int mid = s + (e - s) / 2;
        long long c = 0;
        c += reversePairHelper(nums, temp, s, mid);
        c += reversePairHelper(nums, temp, mid + 1, e);
        c += merge(nums, temp, s, e, mid);
        return c;
    }

public:
    int reversePairs(vector<int>& nums) {
        vector<int> temp(nums.size());
        int s = 0;
        int e = nums.size() - 1;
        long long count = reversePairHelper(nums, temp, s, e);
        return static_cast<int>(count);
    }
};
