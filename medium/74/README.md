# 74. Search a 2D Matrix

#### Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
```
Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
```

### Example 1:
```
Input:
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 3
Output: true
```
### Example 2:
```
Input:
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 13
Output: false
```
## My Solutions:

### CPP:
```cpp
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int N, M, p, r, l, i, j;
        N = matrix.size();
        
        if (N > 0) {
            M = matrix[0].size();
            
            if (M > 0) {
                r = (N * M) - 1;
                l = 0;
                p = 0;
                
                while (r >= l) {
                    p = (r + l) / 2;
                    i = p / M;
                    j = p % M;
                    
                    if (matrix[i][j] == target) {
                        return true;
                    }
                    else if (matrix[i][j] < target) {
                        l = p + 1;
                    }
                    else {
                        r = p - 1;
                    }
                }
            }
        }     
        return false;
    }
};
```
### Python 3:
```python
class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        
        N = len(matrix)
        
        if N > 0:
            M = len(matrix[0])

            if M > 0:
                r = (N * M) - 1
                l = 0
                p = 0

                while r >= l:
                    p = (r + l) // 2
                    i = p // M
                    j = p % M
                    
                    if matrix[i][j] == target:
                        return True
                    elif matrix[i][j] < target:
                        l = p + 1
                    else:
                        r = p - 1

        return False
```
