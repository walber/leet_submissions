# 20. Valid Parentheses

#### Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
#### An input string is valid if:

* Open brackets must be closed by the same type of brackets.
* Open brackets must be closed in the correct order.
* Note that an empty string is also considered valid.

### Example 1:
```
Input: "()"
Output: true
```
### Example 2:
```
Input: "()[]{}"
Output: true
```
### Example 3:
```
Input: "(]"
Output: false
```
### Example 4:
```
Input: "([)]"
Output: false
```
### Example 5:
```
Input: "{[]}"
Output: true
```
## My Solutions:

### CPP:
```cpp
#include <stack>

class Solution {
public:
    bool isValid(string s) {
        std::stack<char> stk;
        int N = s.length();
        char c;
        
        if (N > 0) {
            stk.push(s[0]);
            for (int i = 1; i < N; i++) {
                if (stk.empty()) {
                    stk.push(s[i]);
                }
                else {
                    c = stk.top();
                    
                    if (((c + 1) == s[i]) or ((c + 2) == s[i])) {
                        stk.pop();
                    }
                    else {
                        stk.push(s[i]);
                    }
                }
            }
        }
        
        return stk.empty();
    }
};
```
### Python 3:
```python
class Solution:
    def isValid(self, s: str) -> bool:
        
        N = len(s)
        stack = []
        
        if N > 0:
            stack.append(s[0])

            for i in range(1, N):

                if len(stack) == 0:
                    stack.append(s[i])
                else:
                    c = ord(stack[-1])
                    p = ord(s[i])

                    if ((c + 1) == p) or ((c + 2) == p):
                        stack.pop()
                    else:
                        stack.append(s[i])
        
        return len(stack) == 0
```
