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
        int N, k;
        string s;
        char c;
        N = S.size();

        if (K > 1) {
            sort(S.begin(), S.end());
            return S;
        }

        c = S[0];
        k = 0;
        for (int j = 1; j < N; j++) {
            if (c > S[j]) {
                c = S[j];
                k = j;
            }
        }

        s = S;
        for (int j = k; j < N; j++, k++) {
            if (c == S[k]) {
                S = S.substr(k) + S.substr(0, k);
                k = 0;
                if (lexicographical_compare(S.begin(), S.end(), s.begin(), s.end()) > 0) {
                    s = S;
                }
            }
        }

        return s;
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
```
