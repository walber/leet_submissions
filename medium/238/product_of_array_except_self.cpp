
#include <stack>
#include <algorithm>

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int N, i, p;
        std::stack<int> stk;
        N = nums.size();
        i = 2;
        p = nums[0] * nums[1];
        std::swap(nums[0], nums[1]);
        
        while (i < N) {
            stk.push(nums[i]);
            std::swap(nums[i - 1], nums[i]);
            nums[i - 1] *= nums[i];
            nums[i] = p;
            p *= stk.top();
            i++;
        }

        i = N - 3;
        p = 1;

        while (!stk.empty()) {
            p *= stk.top();
            stk.pop();
            nums[i] *= p;
            i--;
        }

        return nums;
    }
};
