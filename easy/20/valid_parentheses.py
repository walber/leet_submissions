
class Solution:
    def isValid(self, s: str) -> bool:
        
        N = len(s)
        stack = []
        
        if N > 0:
            stack.append(s[0])

            for i in range(1, N):

                if len(stack) == 0:
                    stack.append(s[i])
                else:
                    c = ord(stack[-1])
                    p = ord(s[i])

                    if ((c + 1) == p) or ((c + 2) == p):
                        stack.pop()
                    else:
                        stack.append(s[i])
        
        return len(stack) == 0
