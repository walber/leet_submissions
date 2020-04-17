
class Solution:
    def getSum(self, a: int, b: int) -> int:
        result = a ^ b
        carry = (a & b) << 1
        
        while carry > 0:
            carry = (result & carry) << 1
            result = result ^ carry
        
        return result
