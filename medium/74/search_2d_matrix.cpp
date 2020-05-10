
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
