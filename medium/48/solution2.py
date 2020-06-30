
class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        N = len(matrix)
        matrix.reverse()
        
        for i in range(N):
            for j in range(i + 1, N):
                matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]
