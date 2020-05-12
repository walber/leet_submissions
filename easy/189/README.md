# 189. Rotate Array

#### Given an array, rotate the array to the right by k steps, where k is non-negative.
```
Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.
Could you do it in-place with O(1) extra space?
```
### Example 1:
```
Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]
```
### Example 2:
```
Input: nums = [-1,-100,3,99], k = 2
Output: [3,99,-1,-100]
Explanation: 
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]
```
### Constraints:
- 1 <= nums.length <= 2 * 10^4
- It's guaranteed that nums[i] fits in a 32 bit-signed integer.
- k >= 0

## My Solutions:

### CPP:
```cpp
#include <algorithm>    // std::reverse

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        
        int N = nums.size();
        k = k % N;

        std::reverse(nums.begin(), nums.end());
        std::reverse(nums.begin(), nums.begin() + k);
        std::reverse(nums.begin() + k, nums.end());
    }
};
```
### Python:
```python
class Solution:
    def perform_rotation(self, nums: List[int], s: int, e: int) -> None:
        while s < e:
            nums[s], nums[e] = nums[e], nums[s]
            s += 1
            e -= 1
        
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        N = len(nums)
        k = k % N

        nums.reverse()
        self.perform_rotation(nums, 0, k - 1)
        self.perform_rotation(nums, k, N - 1)
```
