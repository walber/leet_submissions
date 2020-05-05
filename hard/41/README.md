
# 41. First Missing Positive

#### Given an unsorted integer array, find the smallest missing positive integer.

### Example 1:
```
Input: [1,2,0]
Output: 3
```
### Example 2:
```
Input: [3,4,-1,1]
Output: 2
```
### Example 3:
```
Input: [7,8,9,11,12]
Output: 1
```

#### Note:
```
Your algorithm should run in O(n) time and uses constant extra space.
```

## My Solutions:

### CPP:
```cpp
#define ABS(N) ((N<0) ? -N : N)

class Solution {
public:

    int firstMissingPositive(vector<int>& nums) {

        int N, m;
        long j, p;
        N = nums.size();
        j = 0;

        for (int i = 0; i < N; i++) {
            if (nums[i] <= 0) {
                nums[i] = nums[j];
                nums[j] = -1;
                j += 1;
            }
        }

        for (int i = j; i < N; i++) {
            p = j + ABS(nums[i]) - 1;
            if (p < N) {
                nums[p] = nums[p] < 0 ? nums[p] : -nums[p];
            }
        }

        m = 1;
        for (int i = j; i < N; i++) {
            if (nums[i] > 0) {
                return m;
            }
            m += 1;
        }

        return m;
    }
};
```
### Python 3:
```python
class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:

        N = len(nums)
        j = 0

        for i in range(N):
            if nums[i] <= 0:
                nums[i] = nums[j]
                nums[j] = -1
                j += 1
        
        for i in range(j, N):
            p = j + abs(nums[i]) - 1
            if p < N:
                nums[p] = -nums[p] if nums[p] > 0 else nums[p]

        m = 1
        for i in range(j, N):
            if nums[i] > 0:
                return m
            m += 1
        
        return m
```
