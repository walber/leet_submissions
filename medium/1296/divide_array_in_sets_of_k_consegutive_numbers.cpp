
#include <map>

class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        
        int N, key;
        N = nums.size();
        
        if ((N % k) != 0) {
            return false;
        }
        
        std::map<int,int> d;
        
        for (int i : nums) {
            d[i] += 1;
        }
        
        for (auto i = d.begin(); i != d.end(); i++) {
            while (i->second > 0) {
                for (int j = 0; j < k; j++) {
                    key = i->first + j;
                    if (d[key] > 0) {
                        d[key]--;
                    }
                    else {
                        return false;
                    }
                }
            }
        }
        
        return true;
    }
};
