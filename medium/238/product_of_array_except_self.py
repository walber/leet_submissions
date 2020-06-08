
class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:

        N = len(nums)
        stack =[]
        i = 2
        p = nums[0] * nums[1]
        nums[0], nums[1] = nums[1], nums[0]

        while i < N:
            stack.append(nums[i])
            nums[i - 1], nums[i] = nums[i], nums[i - 1]
            nums[i - 1] *= nums[i]
            nums[i] = p
            p *= stack[-1]
            i += 1

        i = N - 3
        p = 1

        while i >= 0:
            p *= stack.pop()
            nums[i] *= p
            i -= 1

        return nums
