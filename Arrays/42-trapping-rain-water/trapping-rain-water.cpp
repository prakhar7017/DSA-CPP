class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int>leftMax(n);// keep track of the maximum height of the left side of the current index
        vector<int>rightMax(n); // keep track of the maximum height of the right side of the current index
        int left=INT_MIN;
        int right=INT_MIN;
        for(int i=0;i<n;i++){
            left=max(left,height[i]);   // find the maximum height of the left side of the current index
            leftMax[i]=left;
            right=max(right,height[n-i-1]); // find the maximum height of the right side of the current index
            rightMax[n-i-1]=right;
        }
        int ans=0;
        for(int i=1;i<n-1;i++){
            int area=min(leftMax[i],rightMax[i])-height[i]; // find the water trapped at the current index . current index sa  left or right ma jo bhi choti height hogi usma sa current building height minus kar do , jitni height bachti ha utni hi water trap hoga
            ans+=area;
        }
        return ans;

    }
};

// time complexity: O(n)
// space complexity: O(n)