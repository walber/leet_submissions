
class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        
        if numRows < 1:
            return []
        
        P = [[1]]
        
        for i in range(numRows-1):
            p = [1]
            for j in range(1, len(P[i])):
                p.append(P[i][j-1] + P[i][j])
            p.append(1)
            P.append(p)
        
        return P
