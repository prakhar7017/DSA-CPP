class Solution {
public:
    vector<vector<int>>result;
    void twoSum(vector<int>& nums,int target,int i,int j){
        while(i<j){
            if(nums[i]+nums[j]>target){
                j--;
            }else if(nums[i]+nums[j]<target){
                i++;
            }else{
                while(i<j && nums[i]==nums[i+1]){
                    i++;
                }
                while(i<j && nums[j]==nums[j-1]){
                    j--;
                }
                result.push_back({-target,nums[i],nums[j]});
                i++;
                j--;
            }
        }
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();

        if (n<3){
            return {};
        }

        result.clear();

        sort(nums.begin(),nums.end());

        for(int i=0;i<n-2;i++){
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }
            twoSum(nums,-nums[i],i+1,n-1);
        }
        return result;
    }


    //   time complexity: O(n^2) n is the size of the array 

    // ref: https://www.youtube.com/watch?v=_cBWWebTVpI&t=1039s&ab_channel=codestorywithMIK 