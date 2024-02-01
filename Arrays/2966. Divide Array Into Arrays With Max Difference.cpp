class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n=nums.size();
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i+=3){
            //i,i+1,i+2
            if((nums[i+2]-nums[i])>k){
                return {};
            }

            ans.push_back({nums[i],nums[i+1],nums[i+2]});
        }
        return ans;;
    }
};

// time complexity: O(nlogn)

//***********************Python Code*********************************
class Solution:
    def divideArray(self, nums: List[int], k: int) -> List[List[int]]:
        n=len(nums)
        ans=[]
        nums.sort()
        for i in range(0,n,3):
            if nums[i+2]-nums[i]>k:
                return []
            else:
                ans.append([nums[i],nums[i+1],nums[i+2]])
        
        return ans


//***********************Typescript Code*********************************
function divideArray(nums: number[], k: number): number[][] {
    let n:number=nums.length;
    let ans:number[][]=new Array();
    nums.sort((a,b)=>a-b);
    for(let i=0;i<n;i+=3){
        if(i + 2 < n && (nums[i+2]-nums[i])>k){
            return [];
        }else{
            ans.push([nums[i],nums[i+1],nums[i+2]]);
        }
    }
    return ans
};

// time complexity: O(nlogn)
