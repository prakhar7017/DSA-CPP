// approach 1 : using element as index and sending that element to its correct position
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        while(i<n){
            int index=nums[i]-1;
            if(nums[i]!=nums[index]){
                swap(nums[i],nums[index]);
            }else{
                ++i;
            }
        }
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(nums[i]!=i+1){
                ans.push_back(nums[i]);
                ans.push_back(i+1);
            }
        }
        return ans;
    }
};

