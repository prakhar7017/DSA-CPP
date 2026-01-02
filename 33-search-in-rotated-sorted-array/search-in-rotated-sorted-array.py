class Solution:
    def findMinimum(self,nums:List[int]):
        n = len(nums)
        left = 0
        right = n-1

        while(left<right):
            mid = left+(right-left)//2
            if nums[mid]>nums[right]:
                left = mid + 1
            else:
                right = mid

        return right    

    def BinarySearch(self,left,right,target,nums):
        while(left<=right):
            mid = left+(right-left)//2
            if nums[mid]==target:
                return mid
            elif nums[mid]<target:
                left = mid + 1
            else:
                right = mid - 1

        return -1                        


    def search(self, nums: List[int], target: int) -> int:
        n = len(nums)
        pivot_index = self.findMinimum(nums)

        idx = self.BinarySearch(0,pivot_index-1,target,nums)

        if idx != -1:
            return idx

        idx = self.BinarySearch(pivot_index,n-1,target,nums)
        return idx 