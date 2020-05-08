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
        int N = nums.size();
        int out = N;
        
        for (int i = 0; i < N; i++)
            out -= nums[i] - i;
        
        return out;
    }
};
```
### Python 3:
```python
class Solution:
    def missingNumber(self, nums: List[int]) -> int:

        N = len(nums)
        out = N
        
        for i in range(N):
            out -= nums[i] - i
        
        return out
```
