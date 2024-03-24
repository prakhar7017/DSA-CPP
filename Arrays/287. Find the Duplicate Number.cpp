class Solution {
    private:
    int usingSortMethod(vector<int>& nums){
        sort(nums.begin(),nums.end());

        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]==nums[i+1]){
                return nums[i];
            }
        }
        return -1;
    }
    int usingBetterApproach(vector<int>& nums){
        int ans=-1;
        for(int i=0;i<nums.size();i++){
            int index=abs(nums[i]);
            if(nums[index]<0){
                ans=index;
                break;
            }
            nums[index]*=-1;
        }
        return ans;;
    }
    int usingPositionMethod(vector<int>& nums){
        while(nums[0]!=nums[nums[0]]){
            swap(nums[0],nums[nums[0]]);
        }
        return nums[0];
    }
public:
    int findDuplicate(vector<int>& nums) {
        return usingPositionMethod(nums);

    }
};


// ------------------------------------------------------------------------------
// slow and fast pointer approach

// move slow pointer by one step and fast pointer by two steps
// where they meet there is a cycle
// now move slow pointer to the start and move both slow and fast pointer by one step to find out dublicate 
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow=nums[0];
        int fast=nums[0];
        slow=nums[slow];
        fast=nums[nums[fast]];

        while(fast!=slow){
            slow=nums[slow];
            fast=nums[nums[fast]];
        }

        slow=nums[0];
        while(slow!=fast){
            slow=nums[slow];
            fast=nums[fast];
        }
        return fast;
    }
};

