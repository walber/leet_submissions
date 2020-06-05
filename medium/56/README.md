# 56. Merge Intervals

#### Given a collection of intervals, merge all overlapping intervals.

### Example 1:
```
Input: [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
```
### Example 2:
```
Input: [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
```

## My Solutions:

### C++:
```cpp
#include <algorithm>

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        if (intervals.size() == 0) {
            return intervals;
        }
        
        int p = 0;
        vector<vector<int>> out;
        
        std::sort(intervals.begin(), intervals.end());
        out.push_back(intervals[0]);

        for (auto interval : intervals) {            
            if (out[p][1] >= interval[0]) {
                out[p][1] = std::max(out[p][1], interval[1]);
            }
            else {
                out.push_back(interval);
                p++;
            }
        }
        
        return out;
    }
};
```
### Python 3:
```python
class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        
        if len(intervals) == 0:
            return intervals

        intervals.sort()
        out = [intervals[0]]

        for interval in intervals:
            
            if out[-1][1] >= interval[0]:
                out[-1][1] = max(interval[1], out[-1][1])
            else:
                out.append(interval)
                
        return out
```
