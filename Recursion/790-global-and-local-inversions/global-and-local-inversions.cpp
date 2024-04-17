class Solution {
public:
    long long getLocal(vector<int>&nums){
        long long count=0;
        int n=nums.size();
        for(int i=0;i<n-1;i++){
            if(nums[i]>nums[i+1]) ++count;
        }
        return count;
    }
    long long merge(vector<int>&nums,int s,int mid,int e){
        int lenLeft=mid-s+1;
        int lenRight=e-mid;

        int *left=new int[lenLeft];
        int *right=new int[lenRight];

        int k=s;
        for(int i=0;i<lenLeft;i++){
            left[i]=nums[k++];
        }
        k=mid+1;
        for(int i=0;i<lenRight;i++){
            right[i]=nums[k++];
        }
        int leftIndex=0;
        int rightIndex=0;
        int mainIndex=s;
        long long c=0;
        while(leftIndex<lenLeft && rightIndex<lenRight){
            if(left[leftIndex]<=right[rightIndex]){
                nums[mainIndex++]=left[leftIndex++];
            }else{
                nums[mainIndex++]=right[rightIndex++];
                c+=lenLeft-leftIndex; // this is the main part of the code which is counting the pairs
            }
        }

        while(leftIndex<lenLeft){
             nums[mainIndex++]=left[leftIndex++];
        }
        while( rightIndex<lenRight){
            nums[mainIndex++]=right[rightIndex++];
        }

        delete[] left;
        delete[] right;
        return c;
    }
    long long getGlobal(vector<int>&nums,int s,int e){
        // base case
        if(s>=e){
            return 0;
        }

        int mid=s+(e-s)/2;
        long long c=0;
        c+=getGlobal(nums,s,mid);
        c+=getGlobal(nums,mid+1,e);
        c+=merge(nums,s,mid,e);
        return c;
    }
    bool isIdealPermutation(vector<int>& nums) {
        long long countLocal=getLocal(nums);
        int n=nums.size();
        int s=0;
        int e=n-1;
        long long countGlobal=getGlobal(nums,s,e);

        return countLocal==countGlobal;
    }
};