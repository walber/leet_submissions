
class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        
        if len(intervals) == 0:
            return intervals

        intervals.sort()
        out = [intervals[0]]

        for interval in intervals:
            
            if out[-1][1] >= interval[0]:
                out[-1][1] = max(interval[1], out[-1][1])
            else:
                out.append(interval)
                
        return out
