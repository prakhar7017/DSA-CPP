class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int>leftMax(n);
        vector<int>rightMax(n);
        int left=INT_MIN;
        int right=INT_MIN;
        for(int i=0;i<n;i++){
            left=max(left,height[i]);
            leftMax[i]=left;
            right=max(right,height[n-i-1]);
            rightMax[n-i-1]=right;
        }
        int ans=0;
        for(int i=1;i<n-1;i++){
            int area=min(leftMax[i],rightMax[i])-height[i];
            ans+=area;
        }
        return ans;

    }
};