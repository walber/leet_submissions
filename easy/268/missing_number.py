
class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        out = 0
        nums_len = len(nums)
        
        for i in range(nums_len + 1):
            out += nums[i] - i if i < nums_len else -i
        
        return -out
