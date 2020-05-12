# 1175. Prime Arrangements

#### Return the number of permutations of 1 to n so that prime numbers are at prime indices (1-indexed.) (Recall that an integer is prime if and only if it is greater than 1, and cannot be written as a product of two positive integers both smaller than it.) Since the answer may be large, return the answer modulo 10^9 + 7.

### Example 1:
```
Input: n = 5
Output: 12
Explanation: For example [1,2,5,4,3] is a valid permutation, but [5,2,3,4,1] is not because the prime number 5 is at index 1.
```
### Example 2:
```
Input: n = 100
Output: 682289015
```
#### Constraints:
```
1 <= n <= 100
```
## My Solutions:

### C++:
```cpp
#define MAX_NUM 1000000007

class Solution {
public:
    long fact(int n) {
        long f = 1;
        
        if (n > 1) {
            for (int i = 2; i <= n; i++) {
                f = (f * i) % MAX_NUM;   
            }
        }
        
        return f % MAX_NUM;
    }

    int numPrimeArrangements(int n) {
        int not_prime = 1;
        vector<bool> num_list(n+1);

        for (int i = n; i > 1; i--) {
            for (int j = 2; j < n; j++) {
                if (i*j <= n) {
                    not_prime += num_list[i*j] ? 0 : 1;
                    num_list[i*j] = true;
                } else {
                    j = n;   
                }
            }
        }

        return (fact(not_prime) * fact(n - not_prime)) % MAX_NUM;
    }
};
```
### Python 3:
```python
class Solution:
    def fact(self, n: int) -> int:
        f = 1

        for i in range(2, n + 1):
            f *= i
                
        return f

    def numPrimeArrangements(self, n: int) -> int:
        not_prime = 1
        num_list = [False] * (n+1)

        for i in range(n, 1, -1):
            for j in range(2, n):
                if i*j <= n:
                    not_prime += 0 if num_list[i*j] else 1
                    num_list[i*j] = True
                else:
                    break

        return (self.fact(not_prime) * self.fact(n - not_prime)) % (10**9 + 7)
```
