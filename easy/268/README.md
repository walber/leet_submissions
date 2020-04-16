# 268. Missing Number

#### Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.

### Example 1:
```
Input: [3,0,1]
Output: 2
```
### Example 2:
```
Input: [9,6,4,2,3,5,7,0,1]
Output: 8
```
## My Solutions:

### C++:
```cpp
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int num_len = nums.size();
        int out = 0;
        
        for (int i = 0; i <= num_len; i++)
            out += i < num_len ? nums[i] - i : -i;
        
        return -out;
    }
};
```
### Python 3:
```python
class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        out = 0
        nums_len = len(nums)
        
        for i in range(nums_len + 1):
            out += nums[i] - i if i < nums_len else -i
        
        return -out
```
