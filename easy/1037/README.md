# 1037. Valid Boomerang

#### A boomerang is a set of 3 points that are all distinct and not in a straight line. Given a list of three points in the plane, return whether these points are a boomerang.

### Example 1:
```
Input: [[1,1],[2,3],[3,2]]
Output: true
```

### Example 2:
```
Input: [[1,1],[2,2],[3,3]]
Output: false
```
## My Solutions:

### C++:
```cpp
class Solution {
public:
    bool isBoomerang(vector<vector<int>>& points) {
        int x, y, x1, y1, x2, y2;
        
        x1 = points[0][0];
        y1 = points[0][1];
        x2 = points[1][0];
        y2 = points[1][1];
        x = points[2][0];
        y = points[2][1];
        
        return (y - y1)*(x2 - x1) != (x - x1)*(y2 - y1);
    }
};
```
### Python 3:
```python
class Solution:
    def isBoomerang(self, points: List[List[int]]) -> bool:
        x1, y1 = points[0]
        x2, y2 = points[1]
        x, y = points[2]
        
        return (y - y1)*(x2 - x1) != (x - x1)*(y2 - y1)
```
