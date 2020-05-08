
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
