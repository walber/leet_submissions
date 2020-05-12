# 172. Fractional Trailing Zeroes

#### Given an integer n, return the number of trailing zeroes in n!.

### Example 1:
```
Input: 3
Output: 0
Explanation: 3! = 6, no trailing zero.
```

### Example 2:
```
Input: 5
Output: 1
Explanation: 5! = 120, one trailing zero.
```
#### Note: Your solution should be in logarithmic time complexity.

## My Solutions:

### C++:
```cpp
class Solution {
public:
    int trailingZeroes(int n) {
        int r = (n - (n % 5)) / 5;
        int trailing_z = 0;
        
        while (r > 0) {
            trailing_z += r;
            r = r / 5;
        }
        
        return trailing_z;
    }
};
```
### Python 3:
```python
class Solution:
    def trailingZeroes(self, n: int) -> int:
        r = (n - (n % 5)) // 5
        trailing_z = 0
        
        while r > 0:
            trailing_z += r
            r = r // 5
            
        return trailing_z
```


