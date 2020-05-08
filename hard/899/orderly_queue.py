
class Solution:
    def orderlyQueue(self, S: str, K: int) -> str:

        N = len(S)

        if K > 1:
            return "".join(sorted(S))

        k = 0
        for j in range(1, N):
            if S[k] > S[j]:
                k = j

        s = S
        c = S[k]
        for j in range(k, N):
            if c == S[k]: 
                S = S[k:] + S[0:k]
                k = 0
                if s > S:
                    s = S
            k += 1

        return s
