
# 661. Image Smoother

#### Given a 2D integer matrix M representing the gray scale of an image, you need to design a smoother to make the gray scale of each cell becomes the average gray scale (rounding down) of all the 8 surrounding cells and itself. If a cell has less than 8 surrounding cells, then use as many as you can.

### Example 1:
```
Input:
[[1,1,1],
 [1,0,1],
 [1,1,1]]
Output:
[[0, 0, 0],
 [0, 0, 0],
 [0, 0, 0]]
```
### Explanation:
```
For the point (0,0), (0,2), (2,0), (2,2): floor(3/4) = floor(0.75) = 0
For the point (0,1), (1,0), (1,2), (2,1): floor(5/6) = floor(0.83333333) = 0
For the point (1,1): floor(8/9) = floor(0.88888889) = 0
```
### Note:
```
The value in the given matrix is in the range of [0, 255].
The length and width of the given matrix are in the range of [1, 150].
```
## My Solutions:

### C++:
```cpp
class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        int r_dim = M.size();
        int c_dim = M[0].size();
        int acc, n_elem;
        vector<vector<int>> output(r_dim, vector<int>(c_dim));
        
        for (int r = 0; r < r_dim; r++) {
            for(int c = 0; c < c_dim; c++) {
                acc = 0;
                n_elem = 0;
                
                for (int i = r-1; i < r+2; i++) {
                    for (int j = c-1; j < c+2; j++) {
                        if (i >= 0 && i < r_dim) {
                            if (j >= 0 && j < c_dim) {
                                acc += M[i][j];
                                n_elem++; 
                            }
                        }
                    }          
                }
                
                output[r][c] = acc / n_elem;
            }
        }
        
        return output;
    }
};
```
### Python 3:
```python
class Solution:
    def imageSmoother(self, M: List[List[int]]) -> List[List[int]]:
        r_dim = len(M)
        c_dim = len(M[0])
        output = [[0 for c in range(c_dim)] for r in range(r_dim)]

        for i in range(r_dim):
            for j in range(c_dim):
                n_elem = 0
                acc = 0

                for a in range(i-1, i+2):
                    for b in range(j-1, j+2):
                        if (a >= 0 and a < r_dim) and (b >= 0 and b < c_dim):
                            acc += M[a][b]
                            n_elem += 1

                output[i][j] = acc // n_elem        

        return output
```
