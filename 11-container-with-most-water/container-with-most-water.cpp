class Solution {
public:
    int bruteforce(vector<int>& height) {
        int maxArea = 0;
        int n = height.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int area = min(height[i], height[j]) * (j - i);
                maxArea = max(maxArea, area);
            }
        }
        return maxArea;
    }
    int optimiszed(vector<int>& height) {
        int maxArea = 0;
        int n = height.size();
        int s = 0;
        int e = n-1;
        while(s<e){
            int area = min(height[s],height[e])*(e-s);
            maxArea = max(area,maxArea);
            if(height[s]<height[e])s++;
            else e--;
        }
        return maxArea;
    }
    int maxArea(vector<int>& height) {return optimiszed(height);}
};