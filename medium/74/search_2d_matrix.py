
class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        
        N = len(matrix)
        
        if N > 0:
            M = len(matrix[0])

            if M > 0:
                r = (N * M) - 1
                l = 0
                p = 0

                while r >= l:
                    p = (r + l) // 2
                    i = p // M
                    j = p % M
                    
                    if matrix[i][j] == target:
                        return True
                    elif matrix[i][j] < target:
                        l = p + 1
                    else:
                        r = p - 1

        return False
