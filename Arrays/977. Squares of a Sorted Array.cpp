
// Problem statement: Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            nums[i]=nums[i]*nums[i];
        }
        sort(begin(nums),end(nums));
        return nums;
    }
};
// time complexity: O(nlogn)
// space complexity: O(1)



// follow up: can you solve it in O(n) time?
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        int j=n-1;
        vector<int>ans(n);
        int k=n-1;
        while(i<=j){
            int a=nums[i]*nums[i];
            int b=nums[j]*nums[j];
            if(b>=a){
                ans[k]=b;
                j--;
            }else{
                ans[k]=a;
                i++;
            }
            k--;

        }
        return ans;
    }
};

// time comexity : O(n)
// space complexity: O(n)