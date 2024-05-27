class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(begin(nums),end(nums));
        int s=0;
        int e=nums.size();
        while(s<=e){
            int mid=s+(e-s)/2;
            int index=lower_bound(begin(nums),end(nums),mid)-begin(nums);
            int count=nums.size()-index;
            if(mid==count){
                return count;
            }else if(count>mid){
                s=mid+1;
            }else{
                e=mid-1;
            }
        }
        return -1;
    }
};