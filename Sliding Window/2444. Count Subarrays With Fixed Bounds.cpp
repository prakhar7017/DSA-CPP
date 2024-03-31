2444. Count Subarrays With Fixed Bounds

// You are given an integer array nums and two integers minK and maxK.

// A fixed-bound subarray of nums is a subarray that satisfies the following conditions:

// The minimum value in the subarray is equal to minK.
// The maximum value in the subarray is equal to maxK.
// Return the number of fixed-bound subarrays.

// A subarray is a contiguous part of an array.

 

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
     int minKPosi=-1;
     int maxKPosi=-1;
     int culIndx=-1;
     long long ans=0;

     for(int i=0;i<nums.size();i++){
        if(nums[i]<minK || nums[i]>maxK){
            culIndx=i;
        }

        if(nums[i]==minK) minKPosi=i;
        if(nums[i]==maxK) maxKPosi=i;

        long long smaller=min(minKPosi,maxKPosi);
        long long temp=smaller-culIndx;
        ans+= temp<=0 ? 0 : temp;
     }   
     return ans;
    }
};

time complexity:O(n)
space complexity:O(1)

// link : https://leetcode.com/problems/count-subarrays-with-fixed-bounds/description/?envType=daily-question&envId=2024-03-31