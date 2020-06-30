
class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        i = 0
        j = len(matrix) - 1

        while i < j:
            for p in range(j-i):
                matrix[i][i + p], matrix[j - p][i], matrix[j][j - p], matrix[i + p][j] = \
                matrix[j - p][i], matrix[j][j - p], matrix[i + p][j], matrix[i][i + p]

            i += 1
            j -= 1
