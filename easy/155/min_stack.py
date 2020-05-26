
class MinStack:

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.min_value = None
        self.stack = []        


    def push(self, x: int) -> None:

        if not self.stack:
            self.stack.append(x)
            self.min_value = x
        else:
            if self.min_value > x:
                self.stack.append((2 * x) - self.min_value)
                self.min_value = x
            else:
                self.stack.append(x)


    def pop(self) -> None:

        if self.stack:
            item = self.stack.pop()
            
            if item < self.min_value:
                item = (2 * self.min_value) - item
                self.min_value = item

            return item

        return None


    def top(self) -> int:

        if self.stack:
            if self.stack[-1] < self.min_value:
                prev_min = (2 * self.min_value) - self.stack[-1]
                return (self.stack[-1] + prev_min) // 2
            else:
                return self.stack[-1]

        return 0


    def getMin(self) -> int:

        return self.min_value if self.min_value else 0

