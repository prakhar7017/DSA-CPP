# The guess API is already defined for you.
# @param num, your guess
# @return -1 if num is higher than the picked number
#          1 if num is lower than the picked number
#          otherwise return 0
# def guess(num: int) -> int:

class Solution:
    def binarySearch(self,left,right):
        while left<=right:
            mid = left+(right-left)//2
            guess_number = guess(mid)
            if guess_number == -1:
                right = mid -1
            elif guess_number == 1:
                left = mid + 1
            else:
                return mid    

        return -1        
    def guessNumber(self, n: int) -> int:
        left = 1
        right = n

        return self.binarySearch(left,right)

        