// 1 approach
//   create two arrays of postive and negative numbers [3,1,2] [-2,-5,-4]
//  then merge them alternatively [3,-2,1,-5,2,-4]
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        int m=n>>1;  // n/2
        vector<int>pos;
        vector<int>neg;
        for(int i=0;i<n;i++){
            if(nums[i]>0){
                pos.push_back(nums[i]);
            }else{
                neg.push_back(nums[i]);
            }
        }
        vector<int>ans;
        int i=0;
        while(i<m){
            int el1=pos[i];
            ans.push_back(el1);
            int el2=neg[i];
            ans.push_back(el2);
            ++i;
        }
        return ans;
    }
};

// 2nd approach
// create two pointers pos and neg
// pos=0 because we want to put positive numbers at even index
// neg=1 because we want to put negative numbers at odd index
// if the number is positive then put it at pos index and increment pos by 2
// if the number is negative then put it at neg index and increment neg by 2
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n);
        int pos=0;
        int neg=1;
        for(int i=0;i<n;i++){
            if(nums[i]>0){
                ans[pos]=nums[i];
                pos+=2;
            }else{
                ans[neg]=nums[i];
                neg+=2;
            }
        }
        return ans;
    }
};
