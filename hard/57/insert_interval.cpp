
#include <map>

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int N, l, r, p, lb, ub;
        std:map<int,int> md;
        vector<int> newItem;
        
        N = intervals.size();
        l = 0;
        
        for (int e : newInterval) {
            r = N - 1;
                
            while (l <= r) {
                p = (l + r) / 2;
                lb = intervals[p][0];
                ub = intervals[p][1];
                
                if (e >= lb) {
                    if (e <= ub) {
                        md[e] = p;
                        break;
                    }
                    else {
                        l = p + 1;
                    }
                }
                else {
                    r = p - 1;
                }
            }
            
            if ((r < l) or (l == N)) {
                newItem.assign(2, e);
                intervals.insert(intervals.begin() + l, newItem);
                md[e] = l;
                N++;
            }
        }
        
        lb = md[newInterval[0]];
        ub = md[newInterval[1]];
        
        int arr [] = {intervals[lb][0], intervals[ub][1]};
        newItem.assign(arr, arr + 2);
        
        intervals.erase(intervals.begin() + lb, intervals.begin() + ub + 1);
        intervals.insert(intervals.begin() + lb, newItem);
        
        return intervals;
    }
};
