
class Solution:
    def imageSmoother(self, M: List[List[int]]) -> List[List[int]]:
        r_dim = len(M)
        c_dim = len(M[0])
        output = [[0 for c in range(c_dim)] for r in range(r_dim)]

        for i in range(r_dim):
            for j in range(c_dim):
                n_elem = 0
                acc = 0

                for a in range(i-1, i+2):
                    for b in range(j-1, j+2):
                        if (a >= 0 and a < r_dim) and (b >= 0 and b < c_dim):
                            acc += M[a][b]
                            n_elem += 1

                output[i][j] = acc // n_elem        

        return output
