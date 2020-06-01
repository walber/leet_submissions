
class Solution:
    def isPossibleDivide(self, nums: List[int], k: int) -> bool:
        
        N = len(nums)
        
        if N % k != 0:
            return False

        nums.sort()
        d = dict(zip(nums, [0] * N))
        for i in nums:
            d[i] += 1

        for i in d:
            while d[i] > 0:
                for j in range(k):
                    if d.get(i + j, 0) > 0:
                        d[i + j] -= 1
                    else:
                        return False

        return True
