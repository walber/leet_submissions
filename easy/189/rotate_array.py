
class Solution:
    def perform_rotation(self, nums: List[int], s: int, e: int) -> None:
        while s < e:
            nums[s], nums[e] = nums[e], nums[s]
            s += 1
            e -= 1
        
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        N = len(nums)
        k = k % N

        nums.reverse()
        self.perform_rotation(nums, 0, k - 1)
        self.perform_rotation(nums, k, N - 1)
