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
