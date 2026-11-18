class Solution {
public:
    int n;
    vector<int> getLeftMax(vector<int>& height) {
        vector<int> leftMax(n, 0);
        leftMax[0] = height[0];
        for (int i = 1; i < n; i++) {
            leftMax[i] = max(height[i], leftMax[i - 1]);
        }
        return leftMax;
    }
    vector<int> getRightMax(vector<int>& height) {
        vector<int> rightMax(n, 0);
        rightMax[n-1] = height[n-1];
        for (int i = n-2; i >=0; i--) {
            rightMax[i] = max(height[i], rightMax[i + 1]);
        }
        return rightMax;
    }
    int trap(vector<int>& height) {
        n = height.size();
        vector<int> leftMax = getLeftMax(height);
        vector<int> rightMax = getRightMax(height);
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=min(leftMax[i],rightMax[i])-height[i];
        }
        return ans;
    }
};