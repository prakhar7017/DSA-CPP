class Solution {
public:
    int detectCycle(vector<int>& nums){
        int n = nums.size();
        int slowIdx = 0;
        int fastIdx = 0;
        while(true){
            slowIdx = nums[slowIdx];
            fastIdx = nums[nums[fastIdx]];
            if(slowIdx == fastIdx) break;
        }
        return slowIdx;
    }
    int findCycleStart(int meetIdx,vector<int>& nums){
        int p1 = 0;
        int p2 =meetIdx;

        while(p1!=p2){
            p1=nums[p1];
            p2=nums[p2];
        }
        return p2;
    }
    int findDuplicate(vector<int>& nums) {
        int meet = detectCycle(nums);
        return findCycleStart(meet,nums);
    }
};