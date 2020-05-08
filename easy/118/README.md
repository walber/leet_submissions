# 118. Pascal's Triangle

#### Given a non-negative integer numRows, generate the first numRows of Pascal's triangle. In Pascal's triangle, each number is the sum of the two numbers directly above it.

### Example:
```
Input: 5
Output:
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
```

## My Solutions:

### C++:
```cpp
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
        vector<vector<int>> P(numRows);
        vector<int> m;
        
        if (numRows < 1) {
            return P;
        }
        
        m.push_back(1);
        P[0] = m;
        m.clear();
        
        for (int i = 0; i < numRows-1; i++) {
            m.push_back(1);

            for (int j = 1; j < P[i].size(); j++) {
                m.push_back(P[i][j-1] + P[i][j]);
            }

            m.push_back(1);
            P[i+1] = m;
            m.clear();
        }
        
        return P;   
    }
};
```
### Python 3:
```python
class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        
        if numRows < 1:
            return []
        
        P = [[1]]
        
        for i in range(numRows-1):
            p = [1]
            for j in range(1, len(P[i])):
                p.append(P[i][j-1] + P[i][j])
            p.append(1)
            P.append(p)
        
        return P
```
