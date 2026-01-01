class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        carry = 1
        for i in range(len(digits)-1,-1,-1):
            total_sum = digits[i]+carry
            carry = total_sum//10
            digits[i]= total_sum%10

        if carry == 1:
            digits.insert(0,1)

        return digits        

        