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


//*******************************PYTHON CODE************************************
class Solution:
    def findErrorNums(self, nums: List[int]) -> List[int]:
        i=0
        n=len(nums)
        while(i<n):
            index=nums[i]-1
            if(nums[i]!=nums[index]):
                nums[i],nums[index]=nums[index],nums[i]
            else:
                i=i+1
        ans = []
        for i in range(n):
            if nums[i] != i + 1:
                ans.append(nums[i])
                ans.append(i + 1)
        
        return ans

//*****************************TypeScript Code**********************************
function findErrorNums(nums: number[]): number[] {
    const n:number=nums.length;
    let i:number=0;
    while(i<n){
        let index:number=nums[i]-1;
        if(nums[i]!=nums[index]){
            [nums[i],nums[index]]=[nums[index],nums[i]];
        }else{
            ++i;
        }
    }
    let ans:number[]=new Array();
    for(let i=0;i<n;i++){
        if(nums[i]!=i+1){
            ans.push(nums[i]);
            ans.push(i+1);
        }
    }
    return ans;
};


        