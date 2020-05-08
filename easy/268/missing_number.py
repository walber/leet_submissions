
class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        
        N = len(nums)
        out = N
        
        for i in range(N):
            out -= nums[i] - i
        
        return out
