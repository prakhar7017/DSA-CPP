// Boyer-Moore Voting Algorithm

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        int el1=NULL;
        int el2=NULL;
        int count1=0;
        int count2=0;
        for(int i=0;i<n;i++){
            if(nums[i]==el1){
                count1++;
            }else if (nums[i]==el2){
                count2++;
            }else if(count1==0){
                count1++;
                el1=nums[i];
            }else if(count2==0){
                count2++;
                el2=nums[i];
            }else{
                count1--;
                count2--;
            }
        }
        int freq1=0;
        int freq2=0;
        vector<int>result;
        for(auto num:nums){
            if(num==el1){
                freq1++;
            }else if(num==el2){
                freq2++;
            }
        }
        if(freq1>floor(n/3)){
            result.push_back(el1);
        }
        if(freq2>floor(n/3)){
            result.push_back(el2);
        }
        return result;
    }
};

// time complexity : O(n) n is the size of the array
//link-> https://www.youtube.com/watch?v=Q6L5SoS-fTo