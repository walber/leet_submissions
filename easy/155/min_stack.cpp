
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
