
class Solution {
public:
    int trailingZeroes(int n) {
        int r = (n - (n % 5)) / 5;
        int trailing_z = 0;
        
        while (r > 0) {
            trailing_z += r;
            r = r / 5;
        }
        
        return trailing_z;
    }
};
