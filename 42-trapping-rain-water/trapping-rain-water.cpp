class Solution {
public:
    int solve(vector<int>& height){
        int n = height.size();
        vector<int>leftMax(n,0);
        vector<int>rightMax(n,0);

        leftMax[0]=height[0];
        rightMax[n-1]=height[n-1];

        for(int i=1;i<n;i++){
            leftMax[i]=max(leftMax[i-1],height[i]);
        }

        for(int i=n-2;i>=0;i--){
            rightMax[i]= max(rightMax[i+1],height[i]);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=min(leftMax[i],rightMax[i])-height[i];
        }
        return ans;
    }
    int trap(vector<int>& height) {
        int n =  height.size();
        int ans = 0;
        int leftMax=0;
        int rightMax=0;

        int leftPtr=0;
        int rightPtr=n-1;

        while(leftPtr<rightPtr){
            leftMax=max(leftMax,height[leftPtr]);
            rightMax=max(rightMax,height[rightPtr]);

            if(leftMax<rightMax){
                ans+=leftMax-height[leftPtr];
                leftPtr++;
            }else{
                ans+=rightMax-height[rightPtr];
                rightPtr--;
            }
        }
        return ans;
    }
};