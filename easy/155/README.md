# 155. Min Stack

#### Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
```
push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
```
### Example 1:
```
Input
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

Output
[null,null,null,null,-3,null,0,-2]
```
```
Explanation
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin(); // return -3
minStack.pop();
minStack.top();    // return 0
minStack.getMin(); // return -2
```

### Constraints:
- Methods pop, top and getMin operations will always be called on non-empty stacks.

## My Solutions:

### CPP:
```cpp
#include <vector>

class MinStack {
public:
    /** initialize your data structure here. */
    std::vector<long> stack;
    long min_val;

    MinStack() {
        this->min_val = 0;
    }
    
    void push(int x) {
        long item = x;
        
        if (this->stack.size() > 0) {
            if (this->min_val > x) {
                item = (2 * (long) x) - this->min_val;
                this->min_val = x;
            }
        }
        else {
            this->min_val = x;
        }
        
        this->stack.push_back(item);
    }
    
    void pop() {
        if (this->stack.size() > 0) {
            long top = this->stack.back();
            
            if (top < min_val) {
                this->min_val = (2 * this->min_val) - top;
            }
            
            this->stack.pop_back();
        }
    }
    
    int top() {
        if (this->stack.size() > 0) {
            long top = this->stack.back();

            if (top <= this->min_val) {
                long prev_min = (2 * this->min_val) - top;
                return (top + prev_min) / 2;
            }
            else {
                return top;
            }
        }

        return 0;
    }
    
    int getMin() {
        return this->min_val;
    }
};
```
### Python 3:
```python
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

```
