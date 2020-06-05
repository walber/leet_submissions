
#include <algorithm>

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        if (intervals.size() == 0) {
            return intervals;
        }
        
        int p = 0;
        vector<vector<int>> out;
        
        std::sort(intervals.begin(), intervals.end());
        out.push_back(intervals[0]);

        for (auto interval : intervals) {            
            if (out[p][1] >= interval[0]) {
                out[p][1] = std::max(out[p][1], interval[1]);
            }
            else {
                out.push_back(interval);
                p++;
            }
        }
        
        return out;
    }
};
