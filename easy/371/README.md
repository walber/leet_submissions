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
	int bitwiseSum(int a, int b) {
		unsigned int result, carry, temp;

		result = a ^ b;
		carry = a & b;
		carry <<= 1;

		while (carry != 0) {
			temp = result ^ carry;
			carry = result & carry;
			carry <<= 1;
			result = temp;
		}

		return result;
	}

	int getSum(int a, int b) {
		bool res_comp1 = false;
		unsigned int carry, result, temp;

		if (a < 0 || b < 0) {
			res_comp1 = true;
			temp = (a < 0) ? a : b;
			b = (temp == a) ? b : a;
			a = bitwiseSum(temp, 1 ^ -1);
			a = bitwiseSum(a, 1);
		}

		result = bitwiseSum(a, b);

		if (res_comp1) {
			result = bitwiseSum(result, 1);
		}

		return result;
	}
};
```
### Python 3 (only positive numbers)
```python
class Solution:
    def getSum(self, a: int, b: int) -> int:
        result = a ^ b
        carry = (a & b) << 1
        
        while carry != 0:
            carry = (result & carry) << 1
            result = result ^ carry
        
        return result
```
