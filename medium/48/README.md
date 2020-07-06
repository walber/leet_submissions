# 48. Rotate Image
#### You are given an n x n 2D matrix representing an image.

#### Rotate the image by 90 degrees (clockwise).
```
Note:

You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.
```
### Example 1:
```
Given input matrix = 
[
  [1,2,3],
  [4,5,6],
  [7,8,9]
],

rotate the input matrix in-place such that it becomes:
[
  [7,4,1],
  [8,5,2],
  [9,6,3]
]
```
### Example 2:
```
Given input matrix =
[
  [ 5, 1, 9,11],
  [ 2, 4, 8,10],
  [13, 3, 6, 7],
  [15,14,12,16]
], 

rotate the input matrix in-place such that it becomes:
[
  [15,13, 2, 5],
  [14, 3, 4, 1],
  [12, 6, 8, 9],
  [16, 7,10,11]
]
```

## My Soluitions:

### C++:
```cpp
#include <algorithm>

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int i, j;
        i = 0;
        j = matrix.size() - 1;
        
        while (i < j) {
            for (int p = j - i; p > 0; p--) {
                std::swap(matrix[i][i + p], matrix[j][j - p]);
                std::swap(matrix[j][j - p], matrix[i + p][j]);
                std::swap(matrix[i][i + p], matrix[j - p][i]);
            }
            i++;
            j--;
        }
    }
};
```
### Python 3:
```python
class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        i = 0
        j = len(matrix) - 1

        while i < j:
            for p in range(j-i):
                matrix[i][i + p], matrix[j - p][i], matrix[j][j - p], matrix[i + p][j] = \
                matrix[j - p][i], matrix[j][j - p], matrix[i + p][j], matrix[i][i + p]

            i += 1
            j -= 1
```
