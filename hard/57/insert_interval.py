
class Solution:
    
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        
        N = len(intervals)        
        md = dict()
        
        l = 0
        for e in newInterval:
            r = N - 1
            
            while l <= r:
                p = (l + r) // 2
                lb, ub = intervals[p]
                
                if e >= lb:
                    if e <= ub:
                        md[e] = p
                        break
                    else:
                        l = p + 1
                else:
                    r = p - 1
            
            if r < l or l == N:
                intervals.insert(l, [e, e])
                md[e] = l
                N += 1                

        lb, ub = md[newInterval[0]], md[newInterval[1]]
        intervals[lb:(ub + 1)] = [[intervals[lb][0], intervals[ub][1]]]
        
        return intervals
