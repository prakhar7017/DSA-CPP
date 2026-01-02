class Solution:
    def findMinimum(self,nums:List[int]):
        n = len(nums)
        left = 0
        right = n-1
        while left<right:
            while left<right and nums[left]==nums[left+1]:
                left+=1

            while left<right and nums[right]==nums[right-1]:
                right-=1

            mid = left+(right-left)//2

            if nums[mid]>nums[right]:
                left = mid+1
            else:
                right = mid

        return right

    def binarySearch(self,left,right,target,nums):
        while left<=right:
            mid = left + (right - left)//2
            if nums[mid] == target:
                return True
            elif nums[mid]>target:
                right = mid - 1
            else:
                left = mid + 1

        return False        


    def search(self, nums: List[int], target: int) -> bool:
        n = len(nums)
        pivot_index = self.findMinimum(nums)
        if self.binarySearch(0,pivot_index-1,target,nums) == True:
            return True
        if self.binarySearch(pivot_index,n-1,target,nums) == True:
            return True

        return False    
        