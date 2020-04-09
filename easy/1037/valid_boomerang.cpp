
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
