
class Solution:
    def orderlyQueue(self, S: str, K: int) -> str:

        N = len(S)

        if K > 1:
            return "".join(sorted(S))
        
        c = S[0]
        k = 0
        for j in range(N):
            if c > S[j]:
                c = S[j]
                k = j

        s = S
        for j in range(k, N):
            if c == S[k]: 
                S = S[k:] + S[0:k]
                k = 0
                if s > S:
                    s = S
            k += 1

        return s
