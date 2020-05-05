# 899. Orderly Queue
#### A string S of lowercase letters is given.  Then, we may make any number of moves. In each move, we choose one of the first K letters (starting from the left), remove it, and place it at the end of the string. Return the lexicographically smallest string we could have after any number of moves.

### Example 1:
```
Input: S = "cba", K = 1
Output: "acb"
```
#### Explanation: 
```
In the first move, we move the 1st character ("c") to the end, obtaining the string "bac".
In the second move, we move the 1st character ("b") to the end, obtaining the final result "acb".
```
### Example 2:
```
Input: S = "baaca", K = 3
Output: "aaabc"
```
#### Explanation:
```
In the first move, we move the 1st character ("b") to the end, obtaining the string "aacab".
In the second move, we move the 3rd character ("c") to the end, obtaining the final result "aaabc".
```
#### Note:
```
1 <= K <= S.length <= 1000
S consists of lowercase letters only.
```
## My Solutions:

### C++:
```cpp
```
### Python 3:
```python
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
```
