
class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:

        N = len(nums)
        j = 0

        for i in range(N):
            if nums[i] <= 0:
                nums[i] = nums[j]
                nums[j] = -1
                j += 1
        
        for i in range(j, N):
            p = j + abs(nums[i]) - 1
            if p < N:
                nums[p] = -nums[p] if nums[p] > 0 else nums[p]

        m = 1
        for i in range(j, N):
            if nums[i] > 0:
                return m
            m += 1
        
        return m

