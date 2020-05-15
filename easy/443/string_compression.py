
class Solution:
    def compress(self, chars: List[str]) -> int:
        N = len(chars)
        c = chars[0]
        i = 0
        k = 0

        while i < N:
            while i < N:
                if c == chars[i]:
                    k += 1
                    i += 1
                else:
                    c = chars[i]
                    break
            
            if k > 1:
                str_k = str(k)
                p = (i - k) + 1
                
                for s in str_k:
                    chars[p] = s
                    p += 1
                
                while p < i:
                    del chars[p]
                    i -= 1
                    N -= 1

            k = 0
        
        return len(chars)
