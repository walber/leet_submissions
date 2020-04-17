# 371. Sum of Two Integers

#### Calculate the sum of two integers a and b, but you are not allowed to use the operator + and -.

### Example 1:
```
Input: a = 1, b = 2
Output: 3
```
### Example 2:
```
Input: a = -2, b = 3
Output: 1
```

## My Solutions:

### C++:
```cpp
class Solution {
public:
    int getSum(int a, int b) {
        int result = a ^ b;
        int carry = (a & b) << 1;
        
        while (carry > 0) {
            carry = (result & carry) << 1;
            result = result ^ carry;   
        }
        
        return result;
    }
};
```
### Python 3
```python
class Solution:
    def getSum(self, a: int, b: int) -> int:
        result = a ^ b
        carry = (a & b) << 1
        
        while carry > 0:
            carry = (result & carry) << 1
            result = result ^ carry
        
        return result
```
