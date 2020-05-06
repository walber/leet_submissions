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
class Solution {
public:
    string orderlyQueue(string S, int K) {
        int N, p, k;
        string s;
        N = S.size();

        if (K > 1) {
            sort(S.begin(), S.end());
            return S;
        }

        p = 0;
        for (int j = 0; j < N; j++) {
            if (S[p] > S[j]) {
                p = j;
            }
        }

        k = p;
        for (int j = p; j < N; j++) {
            if (S[p] == S[k]) {
                s = S.substr(k) + S.substr(0, k);
                if (lexicographical_compare(s.begin(), s.end(), S.begin(), S.end()) > 0) {
                    S = s;
                    p = 0;
                    k = 0;
                }
            }
            k += 1;
        }

        return S;
    }
};
```
### Python 3:
```python
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
```
