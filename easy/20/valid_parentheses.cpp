
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
