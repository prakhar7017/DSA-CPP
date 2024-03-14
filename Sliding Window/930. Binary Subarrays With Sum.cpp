class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int count=0,prefixZeros=0,windowSum=0,i=0,j=0;
        while(j<nums.size()){
            windowSum+=nums[j]; // add current nums[j]

            // i ko agge tab move karna hh jab, yha toh nums[i] ==0 ya phir windowSum> goal
            while(i<j && (nums[i]==0 || windowSum>goal)){ 
                if(nums[i]==1){ // yeh condition yha kyu lgyi hh , becauz yha par iss wali condition windowSum>goal sa bhi pouch skta hu
                    prefixZeros=0; // agar nums[i]==1 , toh dobara prefixZeros reeet kar na padega , kuki subarrays  contineous hoti hh , or agar koi bech ma 1 mil gya toh reset aro
                }else{
                    prefixZeros++; 
                }
                windowSum-=nums[i]; // subtract nums[i]
                i++;
            }
            if(windowSum==goal){
                count+=1+prefixZeros; // 1-> current window + prefixZeros-> no of zeros before current window
            }
            j++;
        }
        return count;

    }
};

// time complexity: O(2*n) -> O(n)
// space complexity: O(1)