# 238. Product of Array Except Self

#### Given an array nums of n integers where n > 1,  return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

### Example:
```
Input:  [1,2,3,4]
Output: [24,12,8,6]
```
#### Constraint: It's guaranteed that the product of the elements of any prefix or suffix of the array (including the whole array) fits in a 32 bit integer.
```
Note: Please solve it without division and in O(n).
```

## My Solutions:

### C++:
```cpp
#include <stack>
#include <algorithm>

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int N, i, p;
        std::stack<int> stk;
        N = nums.size();
        i = 2;
        p = nums[0] * nums[1];
        std::swap(nums[0], nums[1]);
        
        while (i < N) {
            stk.push(nums[i]);
            std::swap(nums[i - 1], nums[i]);
            nums[i - 1] *= nums[i];
            nums[i] = p;
            p *= stk.top();
            i++;
        }

        i = N - 3;
        p = 1;

        while (!stk.empty()) {
            p *= stk.top();
            stk.pop();
            nums[i] *= p;
            i--;
        }

        return nums;
    }
};
```
### Python 3:
```python
class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:

        N = len(nums)
        stack =[]
        i = 2
        p = nums[0] * nums[1]
        nums[0], nums[1] = nums[1], nums[0]

        while i < N:
            stack.append(nums[i])
            nums[i - 1], nums[i] = nums[i], nums[i - 1]
            nums[i - 1] *= nums[i]
            nums[i] = p
            p *= stack[-1]
            i += 1

        i = N - 3
        p = 1

        while i >= 0:
            p *= stack.pop()
            nums[i] *= p
            i -= 1

        return nums
```
