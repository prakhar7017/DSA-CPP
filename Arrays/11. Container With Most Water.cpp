class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans=0;
        int l=0;
        int r=height.size()-1;
        while(l<=r){
            int area=min(height[l],height[r])*(r-l);
            ans=area > ans ? area : ans ;
            if(height[l]<=height[r]){
                l++;
            }else{
                r--;
            }
        }
        return ans;
    }
};

// time complexity: O(n) n is the size of the array 