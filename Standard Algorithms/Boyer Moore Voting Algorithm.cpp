// Leetcode 169. Majority Element

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        int count=0;
        int el=NULL;
        for(int i=0;i<n;i++){
            if(nums[i]==el){
                count++;
            }else if(count==0){
                count++;
                el=nums[i];
            }else{
                count--;
            }
        }
        return el;
    }
};

// time complexity : O(n) n is the size of the array
//link-> https://www.youtube.com/watch?v=Q6L5SoS-fTo