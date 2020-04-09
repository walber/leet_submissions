
class Solution:
    def isBoomerang(self, points: List[List[int]]) -> bool:
        x1, y1 = points[0]
        x2, y2 = points[1]
        x, y = points[2]
        
        return (y - y1)*(x2 - x1) != (x - x1)*(y2 - y1)
