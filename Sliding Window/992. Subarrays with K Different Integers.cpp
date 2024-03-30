// Problem Statement : 992. Subarrays with K Different Integers
// Descrption: Given an integer array nums and an integer k, return the number of good subarrays of nums.

// A good array is an array where the number of different integers in that array is exactly k.

// For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.
// A subarray is a contiguous part of an array

class Solution {
public:
    int solve(vector<int>&nums,int k){
        int n=nums.size();
        int i=0;
        int j=0;
        int count=0;
        unordered_map<int,int>mp; //{element,freq}
        while(j<n){
            mp[nums[j]]++;
            while(i<=j && mp.size() > k){
                mp[nums[i]]--;
                if(mp[nums[i]]==0) mp.erase(nums[i]);
                ++i;
            }
            count+=j-i+1;
            ++j;
        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int ans=solve(nums,k)-solve(nums,k-1);

        return ans;
    }
};

// time complexity : O(n)
// space complexity : O(n)

// link : https://leetcode.com/problems/subarrays-with-k-different-integers/?envType=daily-question&envId=2024-03-30