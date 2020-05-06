
class Solution:
    def orderlyQueue(self, S: str, K: int) -> str:

        N = len(S)

        if K > 1:
            return "".join(sorted(S))

        p = 0
        for j in range(N):
            if S[p] > S[j]:
                p = j

        k = p
        for j in range(p, N):
            if S[p] == S[k]:
                s = S[k:] + S[0:k]
                if S > s:
                    S = s
                    p = 0
                    k = 0
            k += 1

        return S
