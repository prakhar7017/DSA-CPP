class Solution {
public:
    int total=0;
    int solve(int index,int currXor,vector<int>&nums){
        if(index>=nums.size()){
            return currXor;
        }
        int include=solve(index+1,currXor^nums[index],nums);
        int exclude=solve(index+1,currXor,nums);

        return include+exclude;
    }
    int subsetXORSum(vector<int>& nums) {
        return solve(0,0,nums);
    }
};