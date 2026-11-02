class Solution {
public:
    int n;
    int getMax(int idx, bool direction, vector<int>& height) {
        int maxHeight = height[idx];
        if (direction) {
            for (int i = idx; i < n; i++) {
                maxHeight = max(maxHeight, height[i]);
            }
            return maxHeight;
        }
        for (int i = 0; i <= idx; i++) {
            maxHeight = max(maxHeight, height[i]);
        }
        return maxHeight;
    }
    vector<int> getLeftMax(vector<int>& height) {
        vector<int> leftMax(n, 0);
        leftMax[0] = height[0];
        for (int i = 1; i < n; i++) {
            leftMax[i] = max(leftMax[i - 1], height[i]);
        }
        return leftMax;
    }
    vector<int> getRightMax(vector<int>& height) {
        vector<int> rightMax(n, 0);
        rightMax[n-1] = height[n-1];
        for (int i = n-2; i >= 0; i--) {
            rightMax[i] = max(rightMax[i + 1], height[i]);
        }
        return rightMax;
    }
    int bruteForce(vector<int>& height) {
        n = height.size();
        int ans = 0;
        vector<int>leftMax  = getLeftMax(height);
        vector<int>rightMax = getRightMax(height);
        for (int i = 0; i < n; i++) {
            ans += min(leftMax[i], rightMax[i]) - height[i];
        }
        return ans;
    }
    int trap(vector<int>& height) { return bruteForce(height); }
};