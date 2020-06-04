# 57. Insert Interval

#### Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary). You may assume that the intervals were initially sorted according to their start times.

### Example 1:
```
Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
Output: [[1,5],[6,9]]
```
### Example 2:
```
Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
Output: [[1,2],[3,10],[12,16]]
Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].
```
#### NOTE: input types have been changed on April 15, 2019. Please reset to default code definition to get new method signature.

## My Solutions:

### C++:
```cpp
#include <map>

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int N, l, r, p, lb, ub;
        std:map<int,int> md;
        vector<int> newItem;
        
        N = intervals.size();
        l = 0;
        
        for (int e : newInterval) {
            r = N - 1;
                
            while (l <= r) {
                p = (l + r) / 2;
                lb = intervals[p][0];
                ub = intervals[p][1];
                
                if (e >= lb) {
                    if (e <= ub) {
                        md[e] = p;
                        break;
                    }
                    else {
                        l = p + 1;
                    }
                }
                else {
                    r = p - 1;
                }
            }
            
            if ((r < l) or (l == N)) {
                newItem.assign(2, e);
                intervals.insert(intervals.begin() + l, newItem);
                md[e] = l;
                N++;
            }
        }
        
        lb = md[newInterval[0]];
        ub = md[newInterval[1]];
        
        int arr [] = {intervals[lb][0], intervals[ub][1]};
        newItem.assign(arr, arr + 2);
        
        intervals.erase(intervals.begin() + lb, intervals.begin() + ub + 1);
        intervals.insert(intervals.begin() + lb, newItem);
        
        return intervals;
    }
};
```
### Python 3:
```python
class Solution:
    
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        
        N = len(intervals)        
        md = dict()
        
        l = 0
        for e in newInterval:
            r = N - 1
            
            while l <= r:
                p = (l + r) // 2
                lb, ub = intervals[p]
                
                if e >= lb:
                    if e <= ub:
                        md[e] = p
                        break
                    else:
                        l = p + 1
                else:
                    r = p - 1
            
            if r < l or l == N:
                intervals.insert(l, [e, e])
                md[e] = l
                N += 1                

        lb, ub = md[newInterval[0]], md[newInterval[1]]
        intervals[lb:(ub + 1)] = [[intervals[lb][0], intervals[ub][1]]]
        
        return intervals
```
