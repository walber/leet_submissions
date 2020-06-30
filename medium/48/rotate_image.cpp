
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int i, j, t1, t2, t3, t4;
        i = 0;
        j = matrix.size() - 1;
        
        while (i < j) {
            for (int p = 0; p < (j - i); p++) {
                t1 = matrix[j - p][i];
                t2 = matrix[j][j - p];
                t3 = matrix[i + p][j];
                t4 = matrix[i][i + p];
                
                matrix[i][i + p] = t1;
                matrix[j - p][i] = t2;
                matrix[j][j - p] = t3;
                matrix[i + p][j] = t4;
            }
            
            i++;
            j--;
        }
    }
};
