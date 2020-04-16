
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
