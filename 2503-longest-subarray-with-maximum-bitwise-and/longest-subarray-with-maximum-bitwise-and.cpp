class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int max_val = *max_element(nums.begin(), nums.end());  // Find the maximum value
        int max_len = 0, curr_len = 0;

        for (int num : nums) {
            if (num == max_val) {
                curr_len++;  // Increase length if element equals max value
                max_len = max(max_len, curr_len);  // Update max length
            } else {
                curr_len = 0;  // Reset current length when encountering different value
            }
        }
        
        return max_len;  // Return the longest subarray length
    }
};