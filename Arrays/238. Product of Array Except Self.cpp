// Brute Force Approach
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>result(n);
        for(int i=0;i<n;i++){
            int leftP=1;
            int rightP=1;
            for(int j=0;j<i;j++){
                leftP=leftP*nums[j];
            }
            for(int k=i+1;k<n;k++){
                rightP=rightP*nums[k];
            }
            result[i]=leftP*rightP;
        }
        return result;
    }
};

// time complexity: O(n^2)
// space complexity: O(1)

//----------------------------------------------------------------------------------

//optimised approach
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>result(n);

        int countZeros=0,withOutZeros=1;
        for(int num:nums){
            if(num==0){
                countZeros++;
            }else{
                withOutZeros*=num;
            }
        }

        for(int i=0;i<n;i++){
            if(nums[i]!=0){
                if(countZeros>0) result[i]=0;
                else result[i]=withOutZeros/nums[i];
            }else{
                if(countZeros>1) result[i]=0;
                else result[i]=withOutZeros;
            }
        }
        return result;
    }
};

// time complexity: O(n)
// space complexity: O(1)

//----------------------------------------------------------------------------------
// optimised approach
// without division
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>leftP(n);
        vector<int>rightP(n);
        vector<int>result(n);

        leftP[0]=1;
        rightP[n-1]=1;

        for(int i=1;i<n;i++){
            leftP[i]=leftP[i-1]*nums[i-1];
        }
        for(int i=n-2;i>=0;i--){
            rightP[i]=rightP[i+1]*nums[i+1];
        }
        for(int i=0;i<n;i++){
            result[i]=leftP[i]*rightP[i];
        }
        return result;
    }
};

// time complexity: O(n)
// space complexity: O(n)

//----------------------------------------------------------------------------------

// using in o(1) extra space and without division
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>leftP(n);
        vector<int>result(n);

        result[0]=1;

        for(int i=1;i<n;i++){
            result[i]=result[i-1]*nums[i-1];
        }
        int rightP=1;
        for(int i=n-1;i>=0;i--){
            result[i]=result[i]*rightP;
            rightP*=nums[i];
        }
        return result;
    }
};

// time complexity:o(n)
// space complexity:o(1)