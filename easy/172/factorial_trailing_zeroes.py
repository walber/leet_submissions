
class Solution:
    def trailingZeroes(self, n: int) -> int:
        r = (n - (n % 5)) // 5
        trailing_z = 0
        
        while r > 0:
            trailing_z += r
            r = r // 5
            
        return trailing_z
