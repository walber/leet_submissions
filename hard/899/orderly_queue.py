
class Solution:
    def orderlyQueue(self, S: str, K: int) -> str:

        N = len(S)

        if K > 1:
            K = N

        for i in range(K):
            p = i
            
            for j in range(i, N):
                if S[p] > S[j]:
                    p = j

            k = p
            for j in range(p, N):
                if S[p] == S[k]:
                    s = S[0:i] + S[k:] + S[i:k]
                    if S[i:] > s[i:]:
                        S = s
                        p = i
                        k = i
                k += 1

        return S
