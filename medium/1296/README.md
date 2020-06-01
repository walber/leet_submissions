# 1296. Divide Array in Sets of K Consecutive Numbers

#### Given an array of integers nums and a positive integer k, find whether it's possible to divide this array into sets of k consecutive numbers. Return True if its possible otherwise return False.

### Example 1:
```
Input: nums = [1,2,3,3,4,4,5,6], k = 4
Output: true
Explanation: Array can be divided into [1,2,3,4] and [3,4,5,6].
```
### Example 2:
```
Input: nums = [3,2,1,2,3,4,3,4,5,9,10,11], k = 3
Output: true
Explanation: Array can be divided into [1,2,3] , [2,3,4] , [3,4,5] and [9,10,11].
```
### Example 3:
```
Input: nums = [3,3,2,2,1,1], k = 3
Output: true
```
### Example 4:
```
Input: nums = [1,2,3,4], k = 3
Output: false
Explanation: Each array should be divided in subarrays of size 3.
```
#### Constraints:
* 1 <= nums.length <= 10^5
* 1 <= nums[i] <= 10^9
* 1 <= k <= nums.length

## My Solutions:

### C++:
```cpp
#include <map>

class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        
        int N, key;
        N = nums.size();
        
        if ((N % k) != 0) {
            return false;
        }
        
        std::map<int,int> d;
        
        for (int i : nums) {
            d[i] += 1;
        }
        
        for (auto i = d.begin(); i != d.end(); i++) {
            while (i->second > 0) {
                for (int j = 0; j < k; j++) {
                    key = i->first + j;
                    if (d[key] > 0) {
                        d[key]--;
                    }
                    else {
                        return false;
                    }
                }
            }
        }
        
        return true;
    }
};
```
### Python 3:
```python
class Solution:
    def isPossibleDivide(self, nums: List[int], k: int) -> bool:
        
        N = len(nums)
        
        if N % k != 0:
            return False

        nums.sort()
        d = dict(zip(nums, [0] * N))
        for i in nums:
            d[i] += 1

        for i in d:
            while d[i] > 0:
                for j in range(k):
                    if d.get(i + j, 0) > 0:
                        d[i + j] -= 1
                    else:
                        return False

        return True
```
