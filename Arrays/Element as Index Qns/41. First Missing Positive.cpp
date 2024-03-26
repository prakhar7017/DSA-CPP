// Problem Statement : 41. First Missing Positive

// descritpion : Given an unsorted integer array nums.Return the smallest positive integer that is not present in nums.You must implement an algorithm that runs in
// O(n) time and uses 
// O(1) auxiliary space.

class Solution
{
public:
    int firstMissingPositive(vector<int> &nums)
    {
        int n = nums.size();
        vector<bool> vis(n + 1, false);
        for (int i = 0; i < n; i++)
        {
            int index = nums[i];
            if (index <= 0 || index > n)
                continue;
            else
            {
                vis[index] = true;
            }
        }
        for (int i = 1; i <= n; i++)
        {
            if (vis[i] == false)
                return i;
        }
        return n + 1;
    }
};

// time complexity : O(n)
// space complexity : O(n)

// --------------------------------------------------------------------------------


class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        bool one_present=false;
        for(int i=0;i<n;i++){
            if(nums[i]==1) one_present=true;

            if(nums[i]<=0 || nums[i]>n) nums[i]=1; // mujhe kewal [1,n] tak ke no. sa mtlb hh means  ele <= 0 || ele > n mere lye bekar hh , toh replace those eleemnt with 1
        }
        if(one_present==false) return 1;

        for(int i=0;i<n;i++){
            int index=abs(nums[i])-1;
            if(nums[index]<0) continue;
            nums[index]*=-1;
        }

        for(int i=0;i<n;i++){
            if(nums[i]>0) return i+1; 
        }
        return n+1;
    }
};

// time complexity : O(n)
// space complexity : O(1)