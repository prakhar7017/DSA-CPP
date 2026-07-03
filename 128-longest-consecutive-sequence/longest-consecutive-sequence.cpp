class Solution {
public:
    int bruteforce(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        int maxLen = 1;
        unordered_set<int> st(begin(nums), end(nums));

        int n = nums.size();

        for (int i = 0; i < n; i++) {
            int currNum = nums[i];
            int len = 1;
            while (st.find(currNum + 1) != st.end()) {
                len += 1;
                maxLen = max(maxLen, len);
                currNum += 1;
            }
        }
        return maxLen;
    }
    int solveOpti(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int maxLen = 0;

        for (int num : st) {
            if (st.find(num - 1) == st.end()) {
                int currNum = num;
                int len = 1;

                while (st.find(currNum + 1) != st.end()) {
                    currNum++;
                    len++;
                }

                maxLen = max(maxLen, len);
            }
        }

        return maxLen;
    }
    int longestConsecutive(vector<int>& nums) { return solveOpti(nums); }
};